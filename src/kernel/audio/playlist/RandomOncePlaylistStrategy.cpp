#include "RandomOncePlaylistStrategy.h"

#include <algorithm>
#include <stdlib.h>
#include <time.h>

#include "../../converter/Convert.h"

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

    checkRemainingMappings();

	_locker.unlock();
}

bool RandomOncePlaylistStrategy::existInRemainingTracks(string track)
{
    return find(remainingTracks.begin(), remainingTracks.end(), track) != remainingTracks.end();
}

bool RandomOncePlaylistStrategy::checkRemainingMappings()
{
    int tracksSize = remainingTracks.size();
    int mappingsSize = trackToOriginalIndex.size();

    bool check = tracksSize == mappingsSize;

    if (!check)
    {
        logSrv->warn("Remaining Mappings has been diverged: remainingTracks=" + Convert<int>::NumberToString(tracksSize) +  " trackToOriginalIndex=" + Convert<int>::NumberToString(mappingsSize));
    }

    return check;
}

void RandomOncePlaylistStrategy::clonePlaylist()
{
	remainingTracks.clear();
	trackToOriginalIndex.clear();

	for (int i = 0; i < playlist->size(); ++i)
	{
		string track = playlist->read(i);

		trackToOriginalIndex[track] = i;

        if (!existInRemainingTracks(track))
        {
            remainingTracks.push_back(track);
        }
	}

    int tracksSize = remainingTracks.size();
    int mappingsSize = trackToOriginalIndex.size();

    logSrv->info("Playlist cloned: remainingTracks=" + Convert<int>::NumberToString(tracksSize) +  " trackToOriginalIndex=" + Convert<int>::NumberToString(mappingsSize));
}

void RandomOncePlaylistStrategy::removeHistory()
{
	for (int i = 0; i < history->size(); ++i)
	{
		string track = history->read(i);

        removeFromRemainingTracks(track);
        removeFromRemainingMapping(track);
	}
}

void RandomOncePlaylistStrategy::removeFromRemainingMapping(string track)
{
	trackToOriginalIndex.erase(track);
}

void RandomOncePlaylistStrategy::removeFromRemainingTracks(string track)
{
    remainingTracks.erase(remove(remainingTracks.begin(), remainingTracks.end(), track), remainingTracks.end());
}

void RandomOncePlaylistStrategy::removeFromRemainingTracks(int remainingIndex)
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

    int rnd = rand() % size;

    // string rndStr = Convert<int>::NumberToString(rnd);
    // string sizeStr = Convert<int>::NumberToString(size);

    // logSrv->trace("random: " + rndStr + "/" + sizeStr);

	return rnd;
}

bool RandomOncePlaylistStrategy::hasNext(PlaylistItem currentTrack)
{
	_locker.lock();

	bool isEmpty = trackToOriginalIndex.empty();

	if (isEmpty)
	{
        logSrv->info("Playlist is empty, so clone playlist again..");

		clonePlaylist();

		isEmpty = false;
	}

	_locker.unlock();

	return repeat || !isEmpty;
}

PlaylistItem RandomOncePlaylistStrategy::nextTrack(PlaylistItem currentTrack)
{
	_locker.lock();

	PlaylistItem newTrack = currentTrack;


	/* Take a random index from the list of the remaining tracks */
	int remainingIndex = randomLine();


	bool exists = false;
	string randomTrack = "";
	int cnt = 0;
	while (!exists && cnt < 100 && remainingIndex >= 0)
	{
		cnt++;

		/* Get the track based on this index */
		randomTrack = remainingTracks[remainingIndex];


		/* Check is this track exists in the remaining */
		exists = trackExist(randomTrack);


		/* remove this random index from remainings */
		removeFromRemainingTracks(remainingIndex);


		if (!exists)
		{
            string remainingIndexStr = Convert<int>::NumberToString(remainingIndex);

            logSrv->warn("TrackIndex: " + remainingIndexStr + " does not exist, getting new index..");

            remainingIndex = randomLine();
		}
	}


	if (randomTrack == "")
	{
		logSrv->warn("Could not get next track, so take the same..");
	}
	else
	{
		int newTrackIndex = trackToOriginalIndex[randomTrack];

		if (newTrackIndex >= playlist->size())
		{
            string nti = Convert<int>::NumberToString(newTrackIndex);
            string ps = Convert<int>::NumberToString(playlist->size());

            logSrv->warn("newTrackIndex: " + nti + " >= " + ps);

			newTrackIndex = 0;
			randomTrack = remainingTracks[newTrackIndex];
		}

		removeFromRemainingMapping(randomTrack);

		newTrack = getTrack(newTrackIndex);
	}

    checkRemainingMappings();

	_locker.unlock();

	return newTrack;
}
