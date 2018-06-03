#include "PlaylistHandlerFactory.h"

#include "../../di/GlobalAppContext.h"

PlaylistHandlerFactory::PlaylistHandlerFactory(
	const char* playlistFile,
	string historyFile,
	PlaylistStrategyType strategyType,
	bool repeat)
	: strategyType(strategyType),
	repeat(repeat)
{
	logService = inject<ILogService>("logService");
	serializationSrv = inject<ISerializationService>("serializationService");
	AudioTagService* audioTagService = inject<AudioTagService>("audioTagService");

	playlist = new Playlist(playlistFile);
	history = new PlaylistHistory(historyFile);
	metadata = new PlaylistMetadata(playlist, audioTagService);
	stats = new PlaylistStatistics;
}

PlaylistHandlerFactory::~PlaylistHandlerFactory()
{
	if (stats != NULL)
	{
		delete stats;
	}

	if (metadata != NULL)
	{
		delete metadata;
	}

	if (history != NULL)
	{
		delete history;
	}

	if (playlist != NULL)
	{
		delete playlist;
	}
}

PlaylistHandler* PlaylistHandlerFactory::create()
{
	PlaylistHandler* handler = new PlaylistHandler(
		logService,
		serializationSrv,
		playlist,
		history,
		metadata,
		stats,
		strategyType,
		repeat);

	return handler;
}
