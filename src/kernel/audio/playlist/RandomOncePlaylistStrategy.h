#ifndef RandomOncePlaylistStrategy_h__
#define RandomOncePlaylistStrategy_h__

#include "PlaylistStrategy.h"

#include <string>
#include <map>
#include <vector>

using namespace std;

class RandomOncePlaylistStrategy : public PlaylistStrategy
{
private:
	vector<int> originalIndexes;
	map<string, int> trackToRemainingIndex;
	map<int, int> originalIndexToRemainingIndex;

protected:
	virtual void clonePlaylist();
	virtual void removeHistory();
	virtual void removeFromRemaining(string track);
	virtual void removeFromRemaining(int remainingIndex);
	virtual void loadRemaining();

	virtual int randomLine();

public:
	RandomOncePlaylistStrategy(
		ILogService* logSrv,
		Playlist* playlist,
		PlaylistHistory* history,
		PlaylistMetadata* metadata,
		bool repeat);
	virtual ~RandomOncePlaylistStrategy();

	virtual bool hasNext(PlaylistItem currentTrack);
	virtual PlaylistItem nextTrack(PlaylistItem currentTrack);
};

#endif // RandomOncePlaylistStrategy_h__
