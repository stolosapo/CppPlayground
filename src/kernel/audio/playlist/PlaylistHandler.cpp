#include "PlaylistHandler.h"

#include "../../exception/domain/DomainException.h"
#include "exception/PlaylistErrorCode.h"

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
	currentTrack = NULL;
}

PlaylistHandler::~PlaylistHandler()
{

}

AudioTag* PlaylistHandler::nextTrack()
{
	if (strategy == NULL)
	{
		throw DomainException(PlaylistErrorCode::PLS0006);
	}

	currentTrack = strategy->nextTrack(currentTrack);

	return currentTrack->getMetadata();
}
