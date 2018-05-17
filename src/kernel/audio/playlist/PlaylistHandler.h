#ifndef PlaylistHandler_h__
#define PlaylistHandler_h__

#include "../../log/ILogService.h"
#include "../../serialization/ISerializationService.h"
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
	ISerializationService* serializationSrv;
	Playlist* playlist;
	PlaylistHistory* history;
	PlaylistMetadata* metadata;

	PlaylistStrategyType strategyType;
	PlaylistStrategy* strategy;

	Strategy<PlaylistStrategyType, PlaylistStrategy> *pattern;

	bool repeat;

	PlaylistItem currentTrack;

	void registerStrategies();

public:
	PlaylistHandler(
		ILogService* logSrv,
		ISerializationService* serializationSrv,
		Playlist* playlist,
		PlaylistHistory* history,
		PlaylistMetadata* metadata,
		PlaylistStrategyType strategyType,
		bool repeat);
	virtual ~PlaylistHandler();

	void load();
	int playlistSize();

	bool hasNext();
	PlaylistItem nextTrack();
};

#endif // PlaylistHandler_h__
