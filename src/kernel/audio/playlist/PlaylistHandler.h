#ifndef PlaylistHandler_h__
#define PlaylistHandler_h__

#include "../../log/ILogService.h"
#include "Playlist.h"
#include "PlaylistHistory.h"
#include "PlaylistMetadata.h"

class PlaylistHandler
{
private:
	ILogService* logSrv;
	Playlist* playlist;
        PlaylistHistory* history;
        PlaylistMetadata* metadata;

public:
	PlaylistHandler(ILogService* logSrv, Playlist* playlist, PlaylistHistory* history, PlaylistMetadata* metadata);
	virtual ~PlaylistHandler();

        AudioTag* nextTrack();
};

#endif // PlaylistHandler_h__
