#include "PlaylistItem.h"

PlaylistItem::PlaylistItem(int trackIndex, string track, AudioTag* metadata) 
	: trackIndex(trackIndex), track(track), metadata(metadata)
{

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
