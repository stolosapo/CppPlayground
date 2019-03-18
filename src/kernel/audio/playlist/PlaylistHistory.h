#ifndef PlaylistHistory_h__
#define PlaylistHistory_h__

#include <string>
#include <vector>

#include "../../log/ILogService.h"
#include "../../task/Locker.h"

using namespace std;

class PlaylistHistory
{
private:
	Locker _locker;

	string filename;

	vector<string> history;

public:
	PlaylistHistory(string filename);
	virtual ~PlaylistHistory();

	int size();

	void loadAll();
	void load(int lastLines);
	void loadRestOfPlaylistCount(int playlistCount);
	void clear();
	void reloadAll();
	void reload(int lastLines);

	string read(int historyIndex);
	void add(string track);

};

#endif // PlaylistHistory_h__
