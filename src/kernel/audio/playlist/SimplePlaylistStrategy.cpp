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

PlaylistItem* SimplePlaylistStrategy::nextTrack(PlaylistItem* currentTrack)
{
	int currentTrackIndex = 0;

	if (currentTrack != NULL)
	{
		currentTrackIndex = currentTrack->getTrackIndex();
	}

	currentTrackIndex++;

	if (currentTrackIndex >= playlist->size())
	{
		currentTrackIndex = 0;
	}


	string track = playlist->read(currentTrackIndex);
	
}
