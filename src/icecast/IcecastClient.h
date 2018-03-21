#ifndef IcecastClient_h__
#define IcecastClient_h__

#include "config/IcecastClientConfig.h"
#include "IcecastPlaylist.h"
#include "../kernel/log/ILogService.h"
#include "../kernel/interruption/SignalService.h"
#include "../kernel/audio/AudioTagService.h"
#include "libshout/LibShout.h"

class IcecastClient
{
private:
	ILogService *logSrv;
	SignalService* sigSrv;
	AudioTagService *tagSrv;

	IcecastClientConfig* config;
	LibShout* libShout;
	IcecastPlaylist* playlist;

	string getTrackTitle(string filename);
	void logNowPlaying(string filename, string trackTitle);

	void loadConfig();
	void streamAudio();

public:
	IcecastClient(ILogService *logSrv, SignalService *sigSrv, AudioTagService *tagSrv);
	virtual ~IcecastClient();

	static const char* USER_AGENT;

	static const int MAJOR_VERSION = 1;
	static const int MINOR_VERSION = 0;
	static const int PATCH_VERSION = 0;

	static string version();
	static string agentVersion();

	void action();

};

#endif // IcecastClient_h__
