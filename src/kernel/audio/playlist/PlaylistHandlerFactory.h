#ifndef PlaylistHandlerFactory_h__
#define PlaylistHandlerFactory_h__

#include "PlaylistHandler.h"

class PlaylistHandlerFactory
{
private:
	ILogService* logService;
	ISerializationService* serializationSrv;
	ITimeService* timeSrv;

	PlaylistStrategyType strategyType;
	bool repeat;

	Playlist* playlist;
	PlaylistHistory* history;
	PlaylistMetadata* metadata;
	PlaylistStatistics* stats;

public:
	PlaylistHandlerFactory(
		string playlistFile,
		string historyFile,
		PlaylistStrategyType strategyType,
		bool repeat);
	virtual ~PlaylistHandlerFactory();

	PlaylistHandler* create();
};

#endif // PlaylistHandlerFactory_h__
