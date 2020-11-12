#include "PlaylistAudioSource.h"

#include "AudioSourceType.h"
#include "../../kernel/utils/FileHelper.h"

PlaylistAudioSource::PlaylistAudioSource(
    ILogService* logSrv,
    ITimeService* timeSrv,
    AudioEncodingService *encSrv)
    : logSrv(logSrv),
    AudioSource(SOURCE_PLAYLIST),
    NoiseStreamerPlaylist(logSrv, timeSrv, encSrv)
{
    this->currentMp3File = NULL;
    this->currentNssItem = NULL;
}

PlaylistAudioSource::~PlaylistAudioSource()
{
    if (this->currentMp3File != NULL)
    {
        fclose(this->currentMp3File);
        this->currentMp3File = NULL;
    }

    if (this->currentNssItem != NULL)
    {
        archiveTrack(this->currentNssItem);
    }
}

void PlaylistAudioSource::initialize(NoiseStreamerConfig* config)
{
    initializePlaylist(config);
    loadPlaylist();
}

string PlaylistAudioSource::audioMetadata()
{
    if (currentNssItem == NULL)
    {
        loadNextMp3File();
    }

    return nowPlaying().getTrackTitle();
}

void PlaylistAudioSource::logNowPlaying(NoiseStreamerPlaylistItem& nssItem)
{
    if (nssItem.isSuccessEncoded())
    {
        logSrv->info("Playing: " + nssItem.getTrackFile());
    }
    else
    {
        logSrv->warn("Skipping: " + nssItem.getTrack().getTrack());
    }
}

void PlaylistAudioSource::loadNextMp3File()
{
    // First archive previous Playlist item, if any
    if (currentNssItem != NULL)
    {
        cout << "currentNssItem is NOT null" << endl;
        archiveTrack(currentNssItem);
    }

    if (!hasNext())
    {
        cout << "Playlist has NO more items" << endl;
        // Playlist has no more items
        return;
    }

    cout << "Playlist HAS more items" << endl;
    currentNssItem = nextTrack();

    if (!currentNssItem->readyToPlay())
    {
        cout << "currentNssItem is NOT ready to play" << endl;
        currentNssItem->waitToFinishEncode();
    }

    if (!currentNssItem->isSuccessEncoded())
    {
        cout << "currentNssItem is NOT isSuccessEncoded" << endl;
        /* TODO: Should log this track as failed */
        logNowPlaying(*currentNssItem);
        return;
    }

    cout << "currentNssItem is ok: " << currentNssItem->getTrackFile() << endl;
    currentMp3File = FileHelper::openReadBinary(currentNssItem->getTrackFile());

    logNowPlaying(*currentNssItem);
}

FILE* PlaylistAudioSource::mp3File()
{
    if (this->currentMp3File != NULL)
    {
        return this->currentMp3File;
    }

    cout << "File IS null" << endl;
    this->loadNextMp3File();

    return this->currentMp3File;
}

int PlaylistAudioSource::readNextMp3Data(unsigned char* mp3OutBuffer)
{
    FILE* file = mp3File();
    if (file == NULL)
    {
        return 0;
    }

    long read = fread(mp3OutBuffer, 1, sizeof(mp3OutBuffer), file);
    if (read <= 0)
    {
        cout << "no more file read: " << read << endl;
        // Mp3 File finished, so close it.
        fclose(file);
        file = NULL;
    }

    return read;
}
