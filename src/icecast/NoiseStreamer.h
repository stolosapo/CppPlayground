#ifndef NoiseStreamer_h__
#define NoiseStreamer_h__

#include "NoiseStreamerNavigator.h"
#include "config/NoiseStreamerConfig.h"
#include "playlist/NoiseStreamerPlaylist.h"
#include "health/NoiseStreamerHealth.h"
#include "../kernel/log/ILogService.h"
#include "../kernel/time/ITimeService.h"
#include "../kernel/interruption/SignalService.h"
#include "../kernel/audio/AudioTagService.h"
#include "../kernel/audio/encoding/AudioEncodingService.h"
#include "../kernel/version/Version.h"
#include "libshout/LibShout.h"
#include "../kernel/audio/playlist/PlaylistHandlerFactory.h"


class NoiseStreamer : public Version, public NoiseStreamerNavigator, public NoiseStreamerPlaylist, public NoiseStreamerHealth
{
private:
    static const char* USER_AGENT;

	ILogService *logSrv;
	SignalService* sigSrv;
	AudioTagService *tagSrv;
    AudioEncodingService *encSrv;

    string configFilename;

	NoiseStreamerConfig* config;
	LibShout* libShout;

	void logNowPlaying(NoiseStreamerPlaylistItem& nssItem);

	void initializeShout();
    void connectShout();
	void finilizeShout();

	void loadConfig();

    void streamPlaylist();
    void streamNextTrack();
	void streamAudioFile(NoiseStreamerPlaylistItem* nssItem);

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

};

#endif // NoiseStreamer_h__
