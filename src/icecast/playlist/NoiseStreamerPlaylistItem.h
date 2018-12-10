#ifndef NoiseStreamerPlaylistItem_h__
#define NoiseStreamerPlaylistItem_h__

#include "../config/NoiseStreamerConfig.h"
#include "../../kernel/audio/encoding/AudioEncodingService.h"
#include "../../kernel/audio/playlist/PlaylistItem.h"
#include "../../kernel/task/Thread.h"

using namespace std;

class NoiseStreamerPlaylistItem
{
private:
    PlaylistItem track;

    bool needEncode;
    string encodedTrackFile;
    Thread* encodeThread;

    static void* encodeTrack(void* context);

public:
    NoiseStreamerPlaylistItem();
    NoiseStreamerPlaylistItem(PlaylistItem track);
	NoiseStreamerPlaylistItem(PlaylistItem track, Thread* encodeThread);
    NoiseStreamerPlaylistItem(const NoiseStreamerPlaylistItem& item);
	virtual ~NoiseStreamerPlaylistItem();

    PlaylistItem getTrack();
    Thread* getEncodeThread();
    string getTrackFile();
    bool readyToPlay();
    void prepare();

};

#endif // NoiseStreamerPlaylistItem_h__
