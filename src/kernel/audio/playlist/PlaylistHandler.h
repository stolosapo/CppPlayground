#ifndef PlaylistHandler_h__
#define PlaylistHandler_h__

#include "../../log/ILogService.h"
#include "../../strategy/Strategy.h"
#include "Playlist.h"
#include "PlaylistHistory.h"
#include "PlaylistMetadata.h"
#include "PlaylistStrategyType.h"
#include "PlaylistStrategy.h"

class PlaylistHandler
{
private:
	ILogService* logSrv;
	Playlist* playlist;
	PlaylistHistory* history;
	PlaylistMetadata* metadata;

	PlaylistStrategyType strategyType;
	PlaylistStrategy* strategy;

	Strategy<PlaylistStrategyType, PlaylistStrategy> *pattern;

	bool repeat;

	PlaylistItem currentTrack;

	void load();

public:
	PlaylistHandler(
		ILogService* logSrv,
		Playlist* playlist,
		PlaylistHistory* history,
		PlaylistMetadata* metadata,
		PlaylistStrategyType strategyType,
		bool repeat);
	virtual ~PlaylistHandler();

	AudioTag* nextTrack();
};

#endif // PlaylistHandler_h__
