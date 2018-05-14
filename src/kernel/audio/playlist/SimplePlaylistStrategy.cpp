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

bool SimplePlaylistStrategy::hasNext(PlaylistItem* currentTrack)
{
	if (repeat || currentTrack == NULL)
	{
		return true;
	}

	// return currentTrack->getTrackIndex() == playlist->size() - 1;
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
