#ifndef RandomPlaylistStrategy_h__
#define RandomPlaylistStrategy_h__

#include "PlaylistStrategy.h"

class RandomPlaylistStrategy : public PlaylistStrategy
{
protected:
	virtual int randomLine();

public:
	RandomPlaylistStrategy(
		ILogService* logSrv,
		ITimeService* timeSrv,
		Playlist* playlist,
		PlaylistHistory* history,
		PlaylistMetadata* metadata,
		bool repeat);
	virtual ~RandomPlaylistStrategy();

	virtual bool hasNext(PlaylistItem currentTrack);
	virtual PlaylistItem nextTrack(PlaylistItem currentTrack);
};

#endif // RandomPlaylistStrategy_h__
