#ifndef Playlist_h__
#define Playlist_h__

#include <string>
#include <vector>

#include "../../task/Locker.h"

using namespace std;

class Playlist
{
private:
	Locker _locker;

	string filename;

	vector<string> playlist;

public:
	Playlist(string filename);
	virtual ~Playlist();

	int size();

	void load();
	void clear();
	void reload();

	string read(int trackIndex);

};

#endif // Playlist_h__
