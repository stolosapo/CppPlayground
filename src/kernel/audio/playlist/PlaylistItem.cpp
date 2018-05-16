#include "PlaylistItem.h"

#include <iostream>

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

AudioTag* PlaylistItem::getMetadata()
{
	return metadata;
}
