#ifndef PlaylistAudioSource_h__
#define PlaylistAudioSource_h__

#include <string>
#include <fstream>

#include "AudioSource.h"
#include "../playlist/NoiseStreamerPlaylist.h"
#include "../../kernel/interruption/SignalService.h"

using namespace std;

class PlaylistAudioSource: public AudioSource, public NoiseStreamerPlaylist
{
private:
    AudioEncodingService *encSrv;

    FILE *currentMp3File;
    NoiseStreamerPlaylistItem* currentNssItem;

    NoiseStreamerPlaylistItem* fetchNextPlaylistItem();
    bool loadNextPlaylistItem();
    void currentPlaylistItemFinished();

public:
	PlaylistAudioSource(
        ILogService* logSrv,
        SignalService *sigSrv,
        ITimeService* timeSrv,
        AudioEncodingService *encSrv);
	virtual ~PlaylistAudioSource();

    virtual void initialize(AudioSourceConfig config);

    virtual int readNextMp3Data(unsigned char* mp3OutBuffer, size_t buffer_size);
    virtual int readNextEncodedMp3Data(unsigned char* mp3OutBuffer);
};

#endif // PlaylistAudioSource_h__
