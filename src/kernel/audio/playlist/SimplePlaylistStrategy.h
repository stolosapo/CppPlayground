#ifndef SimplePlaylistStrategy_h__
#define SimplePlaylistStrategy_h__

#include "PlaylistStrategy.h"

class SimplePlaylistStrategy : public PlaylistStrategy
{
public:
	SimplePlaylistStrategy(
		ILogService* logSrv,
		ITimeService* timeSrv,
		Playlist* playlist,
		PlaylistHistory* history,
		PlaylistMetadata* metadata,
		bool repeat);
	virtual ~SimplePlaylistStrategy();

	virtual bool hasNext(PlaylistItem currentTrack);
	virtual PlaylistItem nextTrack(PlaylistItem currentTrack);
};

#endif // SimplePlaylistStrategy_h__
