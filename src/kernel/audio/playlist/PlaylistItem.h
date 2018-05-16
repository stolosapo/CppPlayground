#ifndef PlaylistItem_h__
#define PlaylistItem_h__

#include <string>

#include "../AudioTag.h"

using namespace std;

class PlaylistItem
{
private:
	int trackIndex;
	string track;

	AudioTag* metadata;

public:
	PlaylistItem();
	PlaylistItem(int trackIndex, string track, AudioTag* metadata);
	PlaylistItem(const PlaylistItem &item);
	virtual ~PlaylistItem();

	int getTrackIndex();
	string getTrack();
	string getTrackTitle();
	AudioTag* getMetadata();

};

#endif // PlaylistItem_h__
