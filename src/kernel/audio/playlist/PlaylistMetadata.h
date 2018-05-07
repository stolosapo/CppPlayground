#ifndef PlaylistMetadata_h__
#define PlaylistMetadata_h__

#include <string>
#include <map>

#include "Playlist.h"
#include "../AudioTagService.h"
#include "../AudioTag.h"
#include "../../log/ILogService.h"

using namespace std;

class PlaylistMetadata
{
private:
	Playlist* playlist;
	AudioTagService* audioService;

	map<string, AudioTag*> metadata;

public:
	PlaylistMetadata(Playlist* playlist, AudioTagService* audioService);
	virtual ~PlaylistMetadata();

	void loadAll();
	void load(string track);
	void clear();
	void reload();

	bool exist(string track);
	void remove(string track);
	AudioTag* read(string track);

};

#endif // PlaylistMetadata_h__
