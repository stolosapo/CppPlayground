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
	_locker.init();

	srand(time(NULL));
}

RandomOncePlaylistStrategy::~RandomOncePlaylistStrategy()
{
	_locker.destroy();
}

void RandomOncePlaylistStrategy::load()
{
	_locker.lock();

	clonePlaylist();

	removeHistory();

	_locker.unlock();
}

void RandomOncePlaylistStrategy::clonePlaylist()
{
	remainingTracks.clear();
	trackToOriginalIndex.clear();

	for (int i = 0; i < playlist->size(); ++i)
	{
		string track = playlist->read(i);

		remainingTracks.push_back(track);
		trackToOriginalIndex[track] = i;
	}

	cout << "Loaded: " << remainingTracks.size() << ", " << trackToOriginalIndex.size() << endl;
}

void RandomOncePlaylistStrategy::removeHistory()
{
	for (int i = 0; i < history->size(); ++i)
	{
		string track = history->read(i);
		removeFromRemaining(track);
	}

	cout << "Remained: " << remainingTracks.size() << ", " << trackToOriginalIndex.size() << endl;
}

void RandomOncePlaylistStrategy::removeFromRemaining(string track)
{
	trackToOriginalIndex.erase(track);
}

void RandomOncePlaylistStrategy::removeFromRemaining(int remainingIndex)
{
	remainingTracks.erase(remainingTracks.begin() + remainingIndex);
}

bool RandomOncePlaylistStrategy::trackExist(string track)
{
	map<string, int>::iterator it;
	it = trackToOriginalIndex.find(track);

	return it != trackToOriginalIndex.end();
}

int RandomOncePlaylistStrategy::randomLine()
{
	int size = remainingTracks.size();

	if (size == 0)
	{
		return -1;
	}

	return rand() % size;
}

bool RandomOncePlaylistStrategy::hasNext(PlaylistItem currentTrack)
{
	_locker.lock();

	bool isEmpty = trackToOriginalIndex.empty();

	if (isEmpty)
	{
		clonePlaylist();

		isEmpty = false;
	}

	_locker.unlock();

	return repeat || !isEmpty;
}

PlaylistItem RandomOncePlaylistStrategy::nextTrack(PlaylistItem currentTrack)
{
	int remainingIndex = randomLine();

	if (remainingIndex < 0)
	{
		return currentTrack;
	}

	/* Get the track based on this index */
	bool exists = false;
	string randomTrack = "";
	int cnt = 0;
	while (!exists && cnt < 100)
	{
		cnt++;
		randomTrack = remainingTracks[remainingIndex];

		/* Check is this track exists in the remaining */
		exists = trackExist(randomTrack);

		cout << "randomTrack: " << randomTrack << " exists: " << exists << " cnt: " << cnt << endl;

		/* remove this random index from remainings */
		removeFromRemaining(remainingIndex);

		if (!exists)
		{
			remainingIndex = randomLine();
		}
	}

	if (randomTrack == "")
	{
		cerr << "Could not get next track, so take the same.." << endl;
		return currentTrack;
	}


	int newTrackIndex = trackToOriginalIndex[randomTrack];

	if (newTrackIndex >= playlist->size())
	{
		newTrackIndex = 0;
		randomTrack = remainingTracks[newTrackIndex];
	}

	removeFromRemaining(randomTrack);

	cout << "Remained: " << remainingTracks.size() << ", " << trackToOriginalIndex.size() << endl;

	return getTrack(newTrackIndex);
}
