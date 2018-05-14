#ifndef SimplePlaylistStrategy_h__
#define SimplePlaylistStrategy_h__

#include "PlaylistStrategy.h"

class SimplePlaylistStrategy : public PlaylistStrategy
{
public:
	SimplePlaylistStrategy(
		ILogService* logSrv,
		Playlist* playlist,
		PlaylistHistory* history,
		PlaylistMetadata* metadata,
		bool repeat);
	virtual ~SimplePlaylistStrategy();

	AudioTag* nextTrack(int currentTrackIndex);
};

#endif // SimplePlaylistStrategy_h__
