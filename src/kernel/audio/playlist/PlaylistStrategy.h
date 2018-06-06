#ifndef PlaylistStrategy_h__
#define PlaylistStrategy_h__

#include "../../log/ILogService.h"
#include "../../time/ITimeService.h"

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
	ITimeService* timeSrv;

	Playlist* playlist;
	PlaylistHistory* history;
	PlaylistMetadata* metadata;

	bool repeat;

public:
	PlaylistStrategy(
		ILogService* logSrv,
		ITimeService* timeSrv,
		Playlist* playlist,
		PlaylistHistory* history,
		PlaylistMetadata* metadata,
		bool repeat);
	virtual ~PlaylistStrategy();

	virtual PlaylistItem getTrack(int trackIndex);
	virtual void load();
	virtual bool hasNext(PlaylistItem currentTrack) = 0;
	virtual PlaylistItem nextTrack(PlaylistItem currentTrack) = 0;
};

#endif // PlaylistStrategy_h__
