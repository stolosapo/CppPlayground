#include "PlaylistHandler.h"

#include "../../exception/domain/DomainException.h"
#include "exception/PlaylistErrorCode.h"

PlaylistHandler::PlaylistHandler(
	ILogService* logSrv, 
	Playlist* playlist, 
	PlaylistHistory* history, 
	PlaylistMetadata* metadata, 
	PlaylistStrategyType strategyType)
	: logSrv(logSrv), 
	playlist(playlist), 
	history(history), 
	metadata(metadata), 
	strategyType(strategyType)
{

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

	return strategy->nextTrack();
}
