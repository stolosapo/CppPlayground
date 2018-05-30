#include "RandomOncePlaylistStrategy.h"

#include <algorithm>
#include <stdlib.h>
#include <time.h>

RandomOncePlaylistStrategy::RandomOncePlaylistStrategy(
	ILogService* logSrv,
	Playlist* playlist,
	PlaylistHistory* history,
	PlaylistMetadata* metadata,
	bool repeat)
	: PlaylistStrategy(logSrv, playlist, history, metadata, repeat)
{
	srand(time(NULL));

	loadRemaining();
}

RandomOncePlaylistStrategy::~RandomOncePlaylistStrategy()
{

}

void RandomOncePlaylistStrategy::clonePlaylist()
{
	for (int i = 0; i < playlist->size(); ++i)
	{
		string track = playlist->read(i);

		originalIndexes.push_back(i);

		int currentRemainingIndex = originalIndexes.size() - 1;

		trackToRemainingIndex[track] = currentRemainingIndex;
		originalIndexToRemainingIndex[i] = currentRemainingIndex;
	}
}

void RandomOncePlaylistStrategy::removeHistory()
{
	for (int i = 0; i < history->size(); ++i)
	{
		removeFromRemaining(history->read(i));
	}
}

void RandomOncePlaylistStrategy::removeFromRemaining(string track)
{
	// int remainingIndex = trackToRemainingIndex.find(track)->second;

	// int originalIndex = originalIndexes[remainingIndex];

	// originalIndexToRemainingIndex.erase(originalIndex);
	// trackToRemainingIndex.erase(track);
	// originalIndexes.erase(originalIndex);
}

void RandomOncePlaylistStrategy::removeFromRemaining(int remainingIndex)
{
	// int originalIndex = originalIndexes[remainingIndex];
	// string track = playlist->read(originalIndex);

	// originalIndexToRemainingIndex.erase(originalIndex);
	// trackToRemainingIndex.erase(track);
	// originalIndexes.erase(originalIndex);
}

void RandomOncePlaylistStrategy::loadRemaining()
{
	clonePlaylist();

	removeHistory();
}

int RandomOncePlaylistStrategy::randomLine()
{
	int size = originalIndexes.size();

	return rand() % size;
}

bool RandomOncePlaylistStrategy::hasNext(PlaylistItem currentTrack)
{
	bool isEmpty = originalIndexes.empty();

	if (!repeat)
	{
		return isEmpty;
	}

	if (isEmpty)
	{
		clonePlaylist();
	}

	return true;
}

PlaylistItem RandomOncePlaylistStrategy::nextTrack(PlaylistItem currentTrack)
{
	int remainingIndex = randomLine();

	if (remainingIndex >= originalIndexes.size())
	{
		remainingIndex = 0;
	}

	int newTrackIndex = originalIndexes[remainingIndex];

	if (newTrackIndex >= playlist->size())
	{
		newTrackIndex = 0;
	}

	removeFromRemaining(remainingIndex);

	return getTrack(newTrackIndex);
}
