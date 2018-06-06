#include "PlaylistStrategy.h"

PlaylistStrategy::PlaylistStrategy(
	ILogService* logSrv,
	ITimeService* timeSrv,
	Playlist* playlist,
	PlaylistHistory* history,
	PlaylistMetadata* metadata,
	bool repeat)
	: logSrv(logSrv),
	timeSrv(timeSrv),
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

	return PlaylistItem(trackIndex, timeSrv->rawNow(), track, meta);
}

void PlaylistStrategy::load()
{

}
