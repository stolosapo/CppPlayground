#include "PlaylistAsyncMessage.h"

PlaylistAsyncMessage::PlaylistAsyncMessage()
{

}

PlaylistAsyncMessage::~PlaylistAsyncMessage()
{

}

void PlaylistAsyncMessage::setIndex(int index)
{
	this->index = index;
}

void PlaylistAsyncMessage::setFromPlaylistIndex(int fromPlaylistIndex)
{
	this->fromPlaylistIndex = fromPlaylistIndex;
}

void PlaylistAsyncMessage::setToPlaylistIndex(int toPlaylistIndex)
{
	this->toPlaylistIndex = toPlaylistIndex;
}

void PlaylistAsyncMessage::setFilename(const char* filename)
{
	this->filename = filename;
}

void PlaylistAsyncMessage::setHandler(PlaylistHandler* handler)
{
	this->handler = handler;
}

int PlaylistAsyncMessage::getIndex()
{
	return index;
}

int PlaylistAsyncMessage::getFromPlaylistIndex()
{
	return fromPlaylistIndex;
}

int PlaylistAsyncMessage::getToPlaylistIndex()
{
	return toPlaylistIndex;
}

const char* PlaylistAsyncMessage::getFilename()
{
	return filename;
}

PlaylistHandler* PlaylistAsyncMessage::getHandler()
{
	return handler;
}
