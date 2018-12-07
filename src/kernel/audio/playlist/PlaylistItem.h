#ifndef PlaylistItem_h__
#define PlaylistItem_h__

#include <string>
#include <time.h>

#include "../AudioTag.h"

using namespace std;

class PlaylistItem
{
private:
	int trackIndex;
	string track;
	time_t startTime;

	AudioTag* metadata;

public:
	PlaylistItem();
	PlaylistItem(int trackIndex, time_t startTime, string track, AudioTag* metadata);
	PlaylistItem(const PlaylistItem &item);
	virtual ~PlaylistItem();

	int getTrackIndex() const;
	time_t getStartTime();
	string getTrack() const;
	string getTrackTitle() const;
	AudioTag* getMetadata();

    void setStartTime(time_t startTime);

};

#endif // PlaylistItem_h__
