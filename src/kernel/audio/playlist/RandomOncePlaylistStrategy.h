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

    bool existInRemainingTracks(string track);
    bool checkRemainingMappings();

protected:
	virtual void clonePlaylist();
	virtual void removeHistory();
	virtual void removeFromRemainingMapping(string track);
    virtual void removeFromRemainingTracks(string track);
	virtual void removeFromRemainingTracks(int remainingIndex);
	virtual bool trackExist(string track);

	virtual int randomLine();

public:
	RandomOncePlaylistStrategy(
		ILogService* logSrv,
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
