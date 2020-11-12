#ifndef NoiseStreamer_h__
#define NoiseStreamer_h__

#include "NoiseStreamerNavigator.h"
#include "config/NoiseStreamerConfig.h"
#include "playlist/NoiseStreamerPlaylist.h"
#include "health/NoiseStreamerHealth.h"
#include "audio/AudioSource.h"
#include "../kernel/log/ILogService.h"
#include "../kernel/time/ITimeService.h"
#include "../kernel/interruption/SignalService.h"
#include "../kernel/audio/AudioTagService.h"
#include "../kernel/audio/encoding/AudioEncodingService.h"
#include "../kernel/version/Version.h"
#include "libshout/LibShout.h"
#include "../kernel/audio/playlist/PlaylistHandlerFactory.h"


class NoiseStreamer : public Version, public NoiseStreamerNavigator, public NoiseStreamerHealth
{
private:
    static const char* USER_AGENT;

	ILogService *logSrv;
	SignalService* sigSrv;
    ITimeService *timeSrv;
	AudioTagService *tagSrv;
    AudioEncodingService *encSrv;

    string configFilename;

	NoiseStreamerConfig* config;
	LibShout* libShout;
    AudioSource* audioSource;

	void logNowPlaying(NoiseStreamerPlaylistItem& nssItem);

	void initializeShout();
    void connectShout();
	void finilizeShout();

    AudioSource* createNewAudioSource();
    void initializeAudioSource();

	void loadConfig();

    void streamAudioSource();

	static void onLibShoutError(void* sender, EventArgs* e);

public:
	NoiseStreamer(
        ILogService *logSrv,
        SignalService *sigSrv,
        ITimeService *timeSrv,
        AudioTagService *tagSrv,
        AudioEncodingService *encSrv,
        string configFilename);
	virtual ~NoiseStreamer();

	string agentVersion();
    NoiseStreamerConfig* getConfig();

    void initialize();
    void connect();
    void stream();
    void disconnect();
    void shutdownStreamer();
	void action();

    string shoutVersion();
    string shoutError();

    AudioSource* getAudioSource();

};

#endif // NoiseStreamer_h__
