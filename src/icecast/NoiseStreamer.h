#ifndef NoiseStreamer_h__
#define NoiseStreamer_h__

#include "NoiseStreamerNavigator.h"
#include "config/NoiseStreamerConfig.h"
#include "playlist/NoiseStreamerPlaylist.h"
#include "../kernel/log/ILogService.h"
#include "../kernel/interruption/SignalService.h"
#include "../kernel/audio/AudioTagService.h"
#include "../kernel/audio/encoding/AudioEncodingService.h"
#include "../kernel/version/Version.h"
#include "libshout/LibShout.h"
#include "../kernel/audio/playlist/PlaylistHandlerFactory.h"


class NoiseStreamer : public Version, public NoiseStreamerNavigator, public NoiseStreamerPlaylist
{
private:
	ILogService *logSrv;
	SignalService* sigSrv;
	AudioTagService *tagSrv;
    AudioEncodingService *encSrv;

    string configFilename;

	NoiseStreamerConfig* config;
	LibShout* libShout;

	void logNowPlaying(const PlaylistItem& item);

	void initializeShout();

	void loadConfig();
	void streamAudioFile(const PlaylistItem& item);
	bool needReEncode(PlaylistItem& item);
    void reEncodeAudioFile(PlaylistItem item);

	static void onLibShoutError(void* sender, EventArgs* e);

public:
	NoiseStreamer(
        ILogService *logSrv,
        SignalService *sigSrv,
        AudioTagService *tagSrv,
        AudioEncodingService *encSrv,
        string configFilename);
	virtual ~NoiseStreamer();

	static const char* USER_AGENT;

	string agentVersion();

	void action();

	void connectShout();
	void finilizeShout();

	void streamPlaylist();
	void stopPlaying();

};

#endif // NoiseStreamer_h__
