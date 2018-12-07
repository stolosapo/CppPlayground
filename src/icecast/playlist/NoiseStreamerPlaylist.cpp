#include "NoiseStreamerPlaylist.h"

#include "../exception/NoiseStreamerDomainErrorCode.h"
#include "../../kernel/exception/domain/DomainException.h"


NoiseStreamerPlaylist::NoiseStreamerPlaylist(ILogService* logSrv)
    : logSrv(logSrv)
{
    playlistHandlerFactory = NULL;
	playlistHandler = NULL;
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
}

void NoiseStreamerPlaylist::initializePlaylist(NoiseStreamerConfig* config)
{
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

void NoiseStreamerPlaylist::loadPlaylist(NoiseStreamerConfig* config)
{
	string playlistFile = config->getPlaylist();
	string historyFile = config->getHistory();
	playlistHandler->load();
	int size = playlistHandler->playlistSize();
	int historySize = playlistHandler->historySize();

    prepateNextTrack();

	logSrv->info("Playlist: '" + playlistFile + "' loaded, with '" + Convert<int>::NumberToString(size) + "' tracks");
	logSrv->info("History: '" + historyFile + "' loaded, with '" + Convert<int>::NumberToString(historySize) + "' tracks");
}

bool NoiseStreamerPlaylist::hasNext()
{
    return requestedTrackIndex.hasNext() || playlistHandler->hasNext();
}

PlaylistItem NoiseStreamerPlaylist::nextTrack()
{
    if (requestedTrackIndex.hasNext())
    {
        int trackIndex = requestedTrackIndex.getNext();

        currentTrack = playlistHandler->getTrack(trackIndex);
    }
    else
    {
        currentTrack = playlistHandler->nextTrack();
    }

    return currentTrack;
}

void NoiseStreamerPlaylist::prepateNextTrack()
{

}

void NoiseStreamerPlaylist::archiveCurrentTrack()
{
    playlistHandler->archiveTrack(currentTrack);

    numberOfPlayedTracks++;
}

int NoiseStreamerPlaylist::getNumberOfPlayedTracks()
{
	return numberOfPlayedTracks;
}

PlaylistItem NoiseStreamerPlaylist::nowPlaying()
{
	return currentTrack;
}

int NoiseStreamerPlaylist::remainingTrackTime()
{
	return playlistHandler->getRemainingTrackDuration();
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
    requestedTrackIndex.putBack(index);
}
