#include "PlaylistItem.h"

#include <iostream>
#include "../../utils/FileHelper.h"

using namespace std;

PlaylistItem::PlaylistItem()
	: trackIndex(-1), track("")
{

}

PlaylistItem::PlaylistItem(int trackIndex, time_t startTime, string track, AudioTag* metadata)
	: trackIndex(trackIndex), startTime(startTime), track(track), metadata(metadata)
{

}

PlaylistItem::PlaylistItem(const PlaylistItem &item)
{
	trackIndex = item.trackIndex;
	startTime = item.startTime;
	track = item.track;
	metadata = item.metadata;
}

PlaylistItem::~PlaylistItem()
{

}

int PlaylistItem::getTrackIndex()
{
	return trackIndex;
}

time_t PlaylistItem::getStartTime()
{
	return startTime;
}

string PlaylistItem::getTrack()
{
	return track;
}

string PlaylistItem::getTrackTitle()
{
	if (metadata == NULL)
	{
		return FileHelper::filename(track.c_str());
	}

    string delimiter = "";

    if (metadata->getArtist() != "" && metadata->getTitle() != "")
    {
        delimiter = " - ";
    }

	return metadata->getArtist() + delimiter + metadata->getTitle();
}

AudioTag* PlaylistItem::getMetadata()
{
	return metadata;
}
