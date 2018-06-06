#include "RandomPlaylistStrategy.h"

#include <algorithm>
#include <stdlib.h>
#include <time.h>

RandomPlaylistStrategy::RandomPlaylistStrategy(
	ILogService* logSrv,
	ITimeService* timeSrv,
	Playlist* playlist,
	PlaylistHistory* history,
	PlaylistMetadata* metadata,
	bool repeat)
	: PlaylistStrategy(logSrv, timeSrv, playlist, history, metadata, repeat)
{
        srand(time(NULL));
}

RandomPlaylistStrategy::~RandomPlaylistStrategy()
{

}

int RandomPlaylistStrategy::randomLine()
{
	int size = playlist->size();

	return rand() % size;
}

bool RandomPlaylistStrategy::hasNext(PlaylistItem currentTrack)
{
	if (repeat)
	{
		return true;
	}

	int historySize = history->size();
	int playlistSize = playlist->size();

	return historySize < playlistSize;
}

PlaylistItem RandomPlaylistStrategy::nextTrack(PlaylistItem currentTrack)
{
	int currentTrackIndex = currentTrack.getTrackIndex();
	int newTrackIndex = randomLine();

        int cnt = 0;

        while (newTrackIndex == currentTrackIndex &&
                playlist->size() > 1 &&
                cnt < 100)
        {
                cnt++;
                newTrackIndex = randomLine();
        }

	if (newTrackIndex >= playlist->size())
	{
		newTrackIndex = 0;
	}

	return getTrack(newTrackIndex);
}
