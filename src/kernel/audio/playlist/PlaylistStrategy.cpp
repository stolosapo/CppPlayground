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

PlaylistItem PlaylistStrategy::getTrack(int trackIndex)
{
	string track = playlist->read(trackIndex);
	AudioTag* meta = metadata->readAndLoadIfNotExist(track);

	return PlaylistItem(trackIndex, track, meta);
}

int PlaylistStrategy::getTrackIndex(string track)
{
    return playlist->read(track);
}

void PlaylistStrategy::load()
{

}
