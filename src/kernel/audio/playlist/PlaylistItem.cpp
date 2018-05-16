#include "PlaylistItem.h"

#include <iostream>
#include "../../utils/FileHelper.h"

using namespace std;

PlaylistItem::PlaylistItem()
	: trackIndex(-1), track("")
{

}

PlaylistItem::PlaylistItem(int trackIndex, string track, AudioTag* metadata)
	: trackIndex(trackIndex), track(track), metadata(metadata)
{

}

PlaylistItem::PlaylistItem(const PlaylistItem &item)
{
	trackIndex = item.trackIndex;
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

	return metadata->getArtist() + " - " + metadata->getTitle();
}

AudioTag* PlaylistItem::getMetadata()
{
	return metadata;
}
