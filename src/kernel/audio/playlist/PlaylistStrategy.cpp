#include "PlaylistStrategy.h"

PlaylistStrategy::PlaylistStrategy(
	ILogService* logSrv, 
	Playlist* playlist, 
	PlaylistHistory* history, 
	PlaylistMetadata* metadata)
	: logSrv(logSrv), 
	playlist(playlist), 
	history(history), 
	metadata(metadata)
{

}

PlaylistStrategy::~PlaylistStrategy()
{
	
}