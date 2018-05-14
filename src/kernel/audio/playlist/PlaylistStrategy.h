#ifndef PlaylistStrategy_h__
#define PlaylistStrategy_h__

#include "../../log/ILogService.h"
#include "Playlist.h"
#include "PlaylistHistory.h"
#include "PlaylistMetadata.h"
#include "PlaylistStrategyType.h"
#include "PlaylistStrategy.h"
#include "PlaylistItem.h"

class PlaylistStrategy
{
protected:
	ILogService* logSrv;
	Playlist* playlist;
	PlaylistHistory* history;
	PlaylistMetadata* metadata;

	bool repeat;

public:
	PlaylistStrategy(
		ILogService* logSrv,
		Playlist* playlist,
		PlaylistHistory* history,
		PlaylistMetadata* metadata,
		bool repeat);
	virtual ~PlaylistStrategy();

	virtual PlaylistItem* nextTrack(PlaylistItem* currentTrack) = 0;
};

#endif // PlaylistStrategy_h__
