#ifndef PlaylistAsyncMessage_h__
#define PlaylistAsyncMessage_h__

#include "PlaylistHandler.h"

class PlaylistAsyncMessage
{
private:
	int index;
	int fromPlaylistIndex;
	int toPlaylistIndex;
	const char* filename;
	PlaylistHandler* handler;

public:
	PlaylistAsyncMessage();
	virtual ~PlaylistAsyncMessage();

	void setIndex(int index);
	void setFromPlaylistIndex(int fromPlaylistIndex);
	void setToPlaylistIndex(int toPlaylistIndex);
	void setFilename(const char* filename);
	void setHandler(PlaylistHandler* handler);

	int getIndex();
	int getFromPlaylistIndex();
	int getToPlaylistIndex();
	const char* getFilename();
	PlaylistHandler* getHandler();
};

#endif // PlaylistAsyncMessage_h__
