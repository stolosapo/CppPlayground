#ifndef NoiseStreamerAgent_h__
#define NoiseStreamerAgent_h__

#include <string>

#include "../NoiseStreamer.h"
#include "NoiseStreamerAgentArgumentAdapter.h"
#include "../protocol/NoiseStreamerAgentProtocol.h"
#include "../config/NoiseStreamerAgentConfig.h"

#include "../../kernel/tcp/ClientInfo.h"
#include "../../kernel/tcp/server/StatefullTcpServer.h"
#include "../../kernel/interruption/SignalService.h"
#include "../../kernel/time/ITimeService.h"
#include "../../kernel/audio/AudioTagService.h"

using namespace std;

class NoiseStreamerAgent : public TcpServer, public NoiseStreamerAgentArgumentAdapter
{
private:
    AudioTagService *tagSrv;
    AudioEncodingService *encSrv;

	Thread* streamerThread;
	NoiseStreamer *nss;

    NoiseStreamer* noiseStreamer();
    NoiseStreamer* createNewStreamer();
    void disposeStreamerThread();
    void disposeNoiseStreamer();

protected:
	NoiseStreamerAgentProtocol* agentProtocol();
	NoiseStreamerAgentConfig* agentConfig();

	virtual ITcpProtocol* createProtocol();
	virtual string configFilename();
    virtual void loadConfig();
	virtual void initialize();
	virtual void startStreamer();
	virtual bool validateCommand(string command);
	virtual void processCommand(ClientInfo *client, string command);

public:
	NoiseStreamerAgent(
        ILogService *logSrv,
        SignalService *sigSrv,
        ITimeService *timeSrv,
        AudioTagService *tagSrv,
        ArgumentService *argSrv,
        AudioEncodingService *encSrv);
	virtual ~NoiseStreamerAgent();

    friend void* nss_agent_status(void* context);
    friend void* nss_now_playing(void* context);
    friend void* nss_preview_next(void* context);
    friend void* nss_start_client(void* agent);
    friend void* nss_start(void* context);
    friend void* nss_stop_playing(void* context);
    friend void* nss_pause(void* context);
    friend void* nss_resume(void* context);
    friend void* nss_next_track(void* context);
    friend void* nss_request_track(void* context);
    friend void* nss_stats_genre(void* context);
    friend void* nss_stats_artist(void* context);

};

#endif // NoiseStreamerAgent_h__
