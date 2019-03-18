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

    int fromWindow(int limit, int offset);
    int toWindow(int limit, int offset);
    bool inSearchWindow(int found_count, int limit, int offset);
    bool afterSearchWindow(int found_count, int limit, int offset);

public:
	Playlist(string filename);
	virtual ~Playlist();

    static string itemDescription(int index, string track);

	int size();

	void load();
	void clear();
	void reload();

	string read(int trackIndex);
    int read(string track);
    vector<string> search(string query, int limit, int offset);

};

#endif // Playlist_h__
