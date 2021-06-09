#include "PlaylistAudioSource.h"

#include "AudioSourceType.h"
#include "AudioMetadataChangedEventArgs.h"
#include "../../kernel/audio/encoding/lame/LameAudioEncodingService.h"
#include "../../kernel/exception/domain/DomainException.h"
#include "../../kernel/exception/ExceptionMapper.h"
#include "../../kernel/utils/FileHelper.h"

PlaylistAudioSource::PlaylistAudioSource(
    ILogService* logSrv,
    SignalService* sigSrv,
    ITimeService* timeSrv,
    AudioEncodingService *encSrv)
    : AudioSource(logSrv, sigSrv, SOURCE_PLAYLIST),
    NoiseStreamerPlaylist(logSrv, timeSrv, encSrv),
    encSrv(encSrv)
{
    this->currentMp3File = NULL;
    this->currentNssItem = NULL;
}

PlaylistAudioSource::~PlaylistAudioSource()
{
    currentPlaylistItemFinished();
}

void PlaylistAudioSource::initialize(NoiseStreamerConfig* config)
{
    initializePlaylist(config);
    loadPlaylist();
}

NoiseStreamerPlaylistItem* PlaylistAudioSource::fetchNextPlaylistItem()
{
    if (!hasNext())
    {
        // Playlist has no more items
        return NULL;
    }

    NoiseStreamerPlaylistItem* nextNssItem = nextTrack();

    if (!nextNssItem->readyToPlay())
    {
        nextNssItem->waitToFinishEncode();
    }

    if (!nextNssItem->isSuccessEncoded())
    {
        /* TODO: Should log this track as failed */
        AudioSource::logSrv->warn("Skipping: " + nextNssItem->getTrack().getTrack());

        // Fetch next
        return fetchNextPlaylistItem();
    }

    return nextNssItem;
}

bool PlaylistAudioSource::loadNextPlaylistItem()
{
    try
    {
        // Fetch next Playlist item
        NoiseStreamerPlaylistItem* nextNssItem = fetchNextPlaylistItem();
        if (nextNssItem == NULL)
        {
            return false;
        }

        // Set instances
        currentNssItem = nextNssItem;
        currentMp3File = FileHelper::openReadBinary(currentNssItem->getTrackFile());

        AudioSource::logSrv->info("Playing: " + currentNssItem->getTrackFile());

        // Raise audioMetedata Event
        string metadata = nextNssItem->getTrack().getTrackTitle();
        AudioMetadataChangedEventArgs* args =
            new AudioMetadataChangedEventArgs(metadata);
        audioMetadataChanged.raise(this, args);

        return true;
    }
    catch(DomainException& e)
    {
        AudioSource::logSrv->error(handle(e));

        // Raise errorAppeared Event
        errorAppeared.raise(this, NULL);

        // Clear current state
        currentPlaylistItemFinished();

        // and suppress this error
        return false;
    }
}

void PlaylistAudioSource::currentPlaylistItemFinished()
{
    // Close Mp3 file
    if (currentMp3File != NULL)
    {
        fclose(currentMp3File);
        currentMp3File = NULL;
    }

    // Archive playlist item
    if (currentNssItem != NULL)
    {
        archiveTrack(currentNssItem);
        currentNssItem = NULL;
    }
}

int PlaylistAudioSource::readNextMp3Data(unsigned char* mp3OutBuffer, size_t buffer_size)
{
    if (sigSrv->gotSigInt() || isStoped())
    {
        // Mp3 File finished
        currentPlaylistItemFinished();
        return 0;
    }

    if (currentMp3File == NULL || isGoToNext())
    {
        // Bring back to normal in case of goToNext
        normal();

        // load next if any
        bool hasNext = loadNextPlaylistItem();
        if (!hasNext)
        {
            return 0;
        }
    }

    // long read = fread(mp3OutBuffer, 1, sizeof(mp3OutBuffer), currentMp3File);
    long read = fread(mp3OutBuffer, sizeof(char), buffer_size, currentMp3File);
    if (read > 0)
    {
        return read;
    }

    // Mp3 File finished
    currentPlaylistItemFinished();

    // Read next
    return readNextMp3Data(mp3OutBuffer, buffer_size);
}

int PlaylistAudioSource::readNextEncodedMp3Data(unsigned char* mp3OutBuffer)
{
    const int AUDIO_SIZE = 4096;
    unsigned char mp3_buffer[AUDIO_SIZE];
    int read;

    read = readNextMp3Data(mp3_buffer, AUDIO_SIZE);
    cout << "Read next " << read << endl;
    if (read <= 0)
    {
        return 0;
    }

    LameAudioEncodingService* lameEnc =
        (LameAudioEncodingService*) this->encSrv;

    int write = lameEnc->reencode(
        mp3_buffer,
        read,
        mp3OutBuffer,
        currentNssItem->getTrack().getMetadata());

    return write;
}
