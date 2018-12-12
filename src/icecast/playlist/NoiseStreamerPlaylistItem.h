#ifndef NoiseStreamerPlaylistItem_h__
#define NoiseStreamerPlaylistItem_h__

#include "NoiseStreamerEncodeContext.h"
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

    NoiseStreamerEncodeContext* context;

    string reencode();

    static void* encodeTrack(void* context);

public:
    NoiseStreamerPlaylistItem(PlaylistItem track);
	NoiseStreamerPlaylistItem(PlaylistItem track, NoiseStreamerEncodeContext* context);
	virtual ~NoiseStreamerPlaylistItem();

    PlaylistItem getTrack();
    Thread* getEncodeThread();
    string getTrackFile();
    bool readyToPlay();
    void prepare();

};

#endif // NoiseStreamerPlaylistItem_h__
