#include "SimplePlaylistStrategy.h"

SimplePlaylistStrategy::SimplePlaylistStrategy(
	ILogService* logSrv,
	Playlist* playlist,
	PlaylistHistory* history,
	PlaylistMetadata* metadata,
	bool repeat)
	: PlaylistStrategy(logSrv, playlist, history, metadata, repeat)
{

}

SimplePlaylistStrategy::~SimplePlaylistStrategy()
{

}

AudioTag* SimplePlaylistStrategy::nextTrack(int currentTrackIndex)
{

}
