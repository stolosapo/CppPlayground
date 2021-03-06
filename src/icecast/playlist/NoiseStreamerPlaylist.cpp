#include "NoiseStreamerPlaylist.h"

#include "../exception/NoiseStreamerDomainErrorCode.h"
#include "../../kernel/exception/domain/DomainException.h"

NoiseStreamerPlaylist::NoiseStreamerPlaylist(ILogService* logSrv, ITimeService* timeSrv, AudioEncodingService *encSrv)
    : logSrv(logSrv), timeSrv(timeSrv), encSrv(encSrv)
{
    playlistHandlerFactory = NULL;
	playlistHandler = NULL;
    encodePool = new ThreadPool(5);
    numberOfPlayedTracks = 0;
}

NoiseStreamerPlaylist::~NoiseStreamerPlaylist()
{
    if (playlistHandler != NULL)
	{
		delete playlistHandler;
	}

	if (playlistHandlerFactory != NULL)
	{
		delete playlistHandlerFactory;
	}

    if (encodePool != NULL)
    {
        delete encodePool;
    }
}

void NoiseStreamerPlaylist::startTime()
{
    currentTrackStartTime = timeSrv->rawNow();
}

void NoiseStreamerPlaylist::initializePlaylist(NoiseStreamerConfig* config)
{
    this->config = config;

	string playlistFile = config->getPlaylist();
	string historyFile = config->getHistory();
	const char* metadataFile = config->getMetadata().c_str();
	PlaylistStrategyType type = config->getStrategyType();
	bool repeat = config->getRepeat();

	if (type == NONE)
	{
		throw DomainException(NoiseStreamerDomainErrorCode::NSS0022);
	}

	playlistHandlerFactory =
		new PlaylistHandlerFactory(playlistFile, historyFile, type, repeat);

	playlistHandler = playlistHandlerFactory->create();

	logSrv->info("NoiseStreamer playlist initialized!");
}

void NoiseStreamerPlaylist::loadPlaylist()
{
    logSrv->info("NoiseStreamer playlist start loading..");

	string playlistFile = config->getPlaylist();
	string historyFile = config->getHistory();
	playlistHandler->load();
	int size = playlistHandler->playlistSize();
	int historySize = playlistHandler->historySize();

	logSrv->info("Playlist: '" + playlistFile + "' loaded, with '" + Convert<int>::NumberToString(size) + "' tracks");
	logSrv->info("History: '" + historyFile + "' loaded, with '" + Convert<int>::NumberToString(historySize) + "' tracks");

    /* Put the first track into the queue */
    prepareNextTrack();

    /* Wait track to be encoded if needed */
    NoiseStreamerPlaylistItem* firstTrack = mainQueue.front();
    if (firstTrack != NULL)
    {
        firstTrack->waitToFinishEncode();
    }
}

bool NoiseStreamerPlaylist::hasNext()
{
    return mainQueue.hasNext();
}

NoiseStreamerPlaylistItem* NoiseStreamerPlaylist::nextTrack()
{
    NoiseStreamerPlaylistItem* nssItem = mainQueue.getNext();

    prepareNextTrack();

    currentTrack = nssItem->getTrack();

    startTime();

    return nssItem;
}

void NoiseStreamerPlaylist::prepareNextTrack()
{
    if (requestedTrackIndex.hasNext())
    {
        int trackIndex = requestedTrackIndex.getNext();
        PlaylistItem nextTrack = playlistHandler->getTrack(trackIndex);
        mainQueue.putBack(createNssPlaylistItem(nextTrack));
    }
    else if (playlistHandler->hasNext())
    {
        PlaylistItem nextTrack = playlistHandler->nextTrack();
        mainQueue.putBack(createNssPlaylistItem(nextTrack));
    }
}

bool NoiseStreamerPlaylist::needReEncode(PlaylistItem& item)
{
    if (!config->getReencode())
    {
        return false;
    }

    AudioTag* metadata = item.getMetadata();

    int itemSamplerate = metadata->getSamplerate();
    int itemChannels = metadata->getChannels();

    int confSamplerate = Convert<int>::StringToNumber(config->getSamplerate());
    int confChannels = Convert<int>::StringToNumber(config->getChannels());

    return (itemSamplerate != confSamplerate) || (itemChannels != confChannels);
}

NoiseStreamerEncodeContext* NoiseStreamerPlaylist::createEncodeContext(Thread* th)
{
    AudioEncodeMode encodeMode = VBR;
    AudioBitrate audioBitrate = config->getTypedBitrate();
    int samplerate = Convert<int>::StringToNumber(config->getSamplerate());
    int quality = 3;

    return new NoiseStreamerEncodeContext(
        th,
        encSrv,
        logSrv,
        config->getPcmOutPath(),
        config->getMp3OutPath(),
        encodeMode,
        audioBitrate,
        samplerate,
        quality);
}

NoiseStreamerPlaylistItem* NoiseStreamerPlaylist::createNssPlaylistItem(PlaylistItem item)
{
    NoiseStreamerPlaylistItem* nssItem = NULL;

    if (!needReEncode(item))
    {
        nssItem = new NoiseStreamerPlaylistItem(item);
    }
    else if (encodePool->hasNext())
    {
        NoiseStreamerEncodeContext* context = createEncodeContext(encodePool->getNext());
        nssItem = new NoiseStreamerPlaylistItem(item, context);
    }
    else
    {
        logSrv->warn("Encode Pool has no more free threads, so encoding of track will be bypassed");
        nssItem = new NoiseStreamerPlaylistItem(item);
    }

    if (nssItem != NULL)
    {
        nssItem->prepare();
    }

    return nssItem;
}

void NoiseStreamerPlaylist::archiveTrack(NoiseStreamerPlaylistItem* track)
{
    playlistHandler->archiveTrack(track->getTrack());

    /* Return the encode thread back to pool */
    if (track->getEncodeThread() != NULL)
    {
        encodePool->putBack(track->getEncodeThread());
    }

    /* Dispose the encode context */
    if (track->getContext() != NULL)
    {
        delete track->getContext();
    }

    /* Dispose track reference */
    delete track;

    numberOfPlayedTracks++;
}

int NoiseStreamerPlaylist::getNumberOfPlayedTracks()
{
	return numberOfPlayedTracks;
}

int NoiseStreamerPlaylist::queueSize()
{
    return mainQueue.size();
}

int NoiseStreamerPlaylist::requestQueueSize()
{
    return requestedTrackIndex.size();
}

int NoiseStreamerPlaylist::playlistSize()
{
    return playlistHandler->playlistSize();
}

int NoiseStreamerPlaylist::historySize()
{
    return playlistHandler->historySize();
}

string NoiseStreamerPlaylist::history(int historyIndex)
{
    return playlistHandler->getHistoryTrack(historyIndex);
}

int NoiseStreamerPlaylist::trackPlaylistIndex(string track)
{
    return playlistHandler->getTrackIndex(track);
}

PlaylistItem NoiseStreamerPlaylist::nowPlaying()
{
	return currentTrack;
}

PlaylistItem NoiseStreamerPlaylist::previewNext()
{
    NoiseStreamerPlaylistItem* nssItem = mainQueue.front();
    return nssItem->getTrack();
}

PlaylistItem NoiseStreamerPlaylist::previewTrack(int index)
{
    if (index >= playlistHandler->playlistSize() || index < 0)
    {
        throw DomainException(NoiseStreamerDomainErrorCode::NSS0027);
    }

    return playlistHandler->getTrack(index);
}

vector<string> NoiseStreamerPlaylist::searchTracks(string query, int limit, int offset)
{
    return playlistHandler->searchTracks(query, limit, offset);
}

int NoiseStreamerPlaylist::remainingTrackTime()
{
    time_t now = timeSrv->rawNow();

    int progress = difftime(now, currentTrackStartTime);
	int duration = currentTrack.getMetadata()->getDuration();

	int remaining = duration - progress;

	return remaining;
}

string NoiseStreamerPlaylist::getGenreStats()
{
	return playlistHandler->getGenrePercentages();
}

string NoiseStreamerPlaylist::getArtistStats()
{
	return playlistHandler->getArtistPercentages();
}

void NoiseStreamerPlaylist::requestTrack(int index)
{
    if (index >= playlistHandler->playlistSize() || index < 0)
    {
        throw DomainException(NoiseStreamerDomainErrorCode::NSS0027);
    }

    requestedTrackIndex.putBack(index);
}
