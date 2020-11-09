#include "PlaylistAudioSource.h"

#include "../../kernel/utils/FileHelper.h"

PlaylistAudioSource::PlaylistAudioSource(
    ILogService* logSrv,
    ITimeService* timeSrv,
    AudioEncodingService *encSrv)
    : AudioSource(),
    NoiseStreamerPlaylist(logSrv, timeSrv, encSrv)
{
    this->logSrv = logSrv;
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
        archiveTrack(currentNssItem);
    }

    if (!hasNext())
    {
        // Playlist has no more items
        return;
    }

    currentNssItem = nextTrack();

    if (!currentNssItem->readyToPlay())
    {
        currentNssItem->waitToFinishEncode();
    }

    if (!currentNssItem->isSuccessEncoded())
    {
        /* TODO: Should log this track as failed */
        logNowPlaying(*currentNssItem);
        return;
    }

    currentMp3File = FileHelper::openReadBinary(currentNssItem->getTrackFile());

    logNowPlaying(*currentNssItem);
}

FILE* PlaylistAudioSource::mp3File()
{
    if (this->currentMp3File != NULL)
    {
        return this->currentMp3File;
    }

    this->loadNextMp3File();

    return this->currentMp3File;
}

int PlaylistAudioSource::readNextMp3Data(unsigned char* mp3OutBuffer)
{
    if (currentMp3File == NULL)
    {
        return 0;
    }

    int read = fread(mp3OutBuffer, 1, sizeof(mp3OutBuffer), currentMp3File);
    if (read <= 0)
    {
        // Mp3 File finished, so close it.
        fclose(currentMp3File);
        currentMp3File = NULL;
    }

    return read;
}
