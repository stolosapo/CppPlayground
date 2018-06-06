#ifndef RandomOncePlaylistStrategy_h__
#define RandomOncePlaylistStrategy_h__

#include "PlaylistStrategy.h"

#include <string>
#include <map>
#include <vector>

#include "../../task/Locker.h"

using namespace std;

class RandomOncePlaylistStrategy : public PlaylistStrategy
{
private:
	Locker _locker;

	vector<string> remainingTracks;
	map<string, int> trackToOriginalIndex;

protected:
	virtual void clonePlaylist();
	virtual void removeHistory();
	virtual void removeFromRemaining(string track);
	virtual void removeFromRemaining(int remainingIndex);
	virtual bool trackExist(string track);

	virtual int randomLine();

public:
	RandomOncePlaylistStrategy(
		ILogService* logSrv,
		ITimeService* timeSrv,
		Playlist* playlist,
		PlaylistHistory* history,
		PlaylistMetadata* metadata,
		bool repeat);
	virtual ~RandomOncePlaylistStrategy();

	virtual void load();
	virtual bool hasNext(PlaylistItem currentTrack);
	virtual PlaylistItem nextTrack(PlaylistItem currentTrack);
};

#endif // RandomOncePlaylistStrategy_h__
