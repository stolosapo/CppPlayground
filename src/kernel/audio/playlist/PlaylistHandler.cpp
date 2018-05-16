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

	load();

	strategy = pattern->get(strategyType);
}

PlaylistHandler::~PlaylistHandler()
{
	if (pattern != NULL)
	{
		delete pattern;
	}

	if (strategy != NULL)
	{
		delete strategy;
	}
}

void PlaylistHandler::load()
{
	pattern->registerStrategy(SIMPLE, new SimplePlaylistStrategy(logSrv, playlist, history, metadata, repeat));
}

AudioTag* PlaylistHandler::nextTrack()
{
	if (strategy == NULL)
	{
		throw DomainException(PlaylistErrorCode::PLS0006);
	}

	currentTrack = strategy->nextTrack(currentTrack);

	return currentTrack.getMetadata();
}
