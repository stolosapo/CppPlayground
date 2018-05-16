#ifndef PlaylistHandlerFactory_h__
#define PlaylistHandlerFactory_h__

#include "PlaylistHandler.h"

class PlaylistHandlerFactory
{
private:
	ILogService* logService;
	const char* playlistFile;
	const char* historyFile;
	PlaylistStrategyType strategyType;
	bool repeat;
	
	Playlist* playlist;
	PlaylistHistory* history;
	PlaylistMetadata* metadata;

public:
	PlaylistHandlerFactory(
		const char* playlistFile,
		const char* historyFile,
		PlaylistStrategyType strategyType,
		bool repeat);
	virtual ~PlaylistHandlerFactory();

	PlaylistHandler* create();
};

#endif // PlaylistHandlerFactory_h__
