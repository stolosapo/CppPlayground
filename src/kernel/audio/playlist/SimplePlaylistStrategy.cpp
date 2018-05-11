#include "SimplePlaylistStrategy.h"

SimplePlaylistStrategy::SimplePlaylistStrategy(
	ILogService* logSrv, 
	Playlist* playlist, 
	PlaylistHistory* history, 
	PlaylistMetadata* metadata) 
	: PlaylistStrategy(logSrv, playlist, history, metadata)
{

}

SimplePlaylistStrategy::~SimplePlaylistStrategy()
{

}

AudioTag* SimplePlaylistStrategy::nextTrack()
{

}