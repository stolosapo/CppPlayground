#ifndef PlaylistAudioSource_h__
#define PlaylistAudioSource_h__

#include <string>
#include <fstream>

#include "AudioSource.h"
#include "../playlist/NoiseStreamerPlaylist.h"

using namespace std;

class PlaylistAudioSource: public AudioSource, public NoiseStreamerPlaylist
{
private:
    ILogService* logSrv;

    FILE *currentMp3File;
    NoiseStreamerPlaylistItem* currentNssItem;

    FILE* mp3File();
    void loadNextMp3File();
    void logNowPlaying(NoiseStreamerPlaylistItem& nssItem);

public:
	PlaylistAudioSource(
        ILogService* logSrv,
        ITimeService* timeSrv,
        AudioEncodingService *encSrv);
	virtual ~PlaylistAudioSource();

    virtual void initialize(NoiseStreamerConfig* config);

    virtual string audioMetadata();

    virtual int readNextMp3Data(unsigned char* mp3OutBuffer);
};

#endif // PlaylistAudioSource_h__
