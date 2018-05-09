#include "PlaylistHandler.h"

PlaylistHandler::PlaylistHandler(ILogService* logSrv, Playlist* playlist, PlaylistHistory* history, PlaylistMetadata* metadata)
        : logSrv(logSrv), playlist(playlist), history(history), metadata(metadata)
{

}

PlaylistHandler::~PlaylistHandler()
{

}

AudioTag* PlaylistHandler::nextTrack()
{
        
}
