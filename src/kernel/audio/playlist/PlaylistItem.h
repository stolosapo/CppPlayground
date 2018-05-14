#ifndef PlaylistItem
#define PlaylistItem

#include <string>
#include <map>

#include "Playlist.h"
#include "../AudioTagService.h"
#include "../AudioTag.h"
#include "../../log/ILogService.h"

using namespace std;

class PlaylistItem
{
private:
	int trackIndex;
	string track;

	AudioTag* metadata;

public:
	PlaylistItem(int trackIndex, AudioTagService* audioService);
	virtual ~PlaylistItem();

	void loadAll();
	void load(string track);
	void clear();
	void reload();

	bool exist(string track);
	void remove(string track);
	AudioTag* read(string track);

};

#endif // PlaylistItem
