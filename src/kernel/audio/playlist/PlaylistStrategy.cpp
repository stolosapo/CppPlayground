#include "PlaylistStrategy.h"

PlaylistStrategy::PlaylistStrategy(
	ILogService* logSrv,
	Playlist* playlist,
	PlaylistHistory* history,
	PlaylistMetadata* metadata,
	bool repeat)
	: logSrv(logSrv),
	playlist(playlist),
	history(history),
	metadata(metadata),
	repeat(repeat)
{

}

PlaylistStrategy::~PlaylistStrategy()
{

}
