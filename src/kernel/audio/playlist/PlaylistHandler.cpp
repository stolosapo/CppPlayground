#include "PlaylistHandler.h"

#include "../../exception/domain/DomainException.h"
#include "exception/PlaylistErrorCode.h"
#include "SimplePlaylistStrategy.h"

PlaylistHandler::PlaylistHandler(
	ILogService* logSrv,
	Playlist* playlist,
	PlaylistHistory* history,
	PlaylistMetadata* metadata,
	PlaylistStrategyType strategyType,
	bool repeat)
	: logSrv(logSrv),
	playlist(playlist),
	history(history),
	metadata(metadata),
	strategyType(strategyType),
	repeat(repeat)
{
	pattern = new Strategy<PlaylistStrategyType, PlaylistStrategy>;

	registerStrategies();

	strategy = pattern->get(strategyType);
}

PlaylistHandler::~PlaylistHandler()
{
	if (pattern != NULL)
	{
		delete pattern;
	}
}

void PlaylistHandler::registerStrategies()
{
	pattern->registerStrategy(SIMPLE, new SimplePlaylistStrategy(logSrv, playlist, history, metadata, repeat));
}

void PlaylistHandler::load()
{
	if (playlist != NULL)
	{
		playlist->load();
	}
}

int PlaylistHandler::playlistSize()
{
	if (playlist == NULL)
	{
		return -1;
	}

	return playlist->size();
}

bool PlaylistHandler::hasNext()
{
	if (strategy == NULL)
	{
		throw DomainException(PlaylistErrorCode::PLS0006);
	}

	return strategy->hasNext(currentTrack);
}

PlaylistItem PlaylistHandler::nextTrack()
{
	if (strategy == NULL)
	{
		throw DomainException(PlaylistErrorCode::PLS0006);
	}

	currentTrack = strategy->nextTrack(currentTrack);

	return currentTrack;
}
