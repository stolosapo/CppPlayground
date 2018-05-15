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

bool SimplePlaylistStrategy::hasNext(PlaylistItem currentTrack)
{
	if (repeat)
	{
		return true;
	}

	int index = currentTrack.getTrackIndex();
	int size = playlist->size();

	return index < size;
}

PlaylistItem SimplePlaylistStrategy::nextTrack(PlaylistItem currentTrack)
{
	int currentTrackIndex = currentTrack.getTrackIndex();

	currentTrackIndex++;

	if (currentTrackIndex >= playlist->size())
	{
		currentTrackIndex = 0;
	}

	string track = playlist->read(currentTrackIndex);
	AudioTag* meta = metadata->readAndLoadIfNotExist(track);

	PlaylistItem item(currentTrackIndex, track, meta);

	return item;
}
