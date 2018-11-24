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

	Thread* icecastThread;
	NoiseStreamer *icecast;

    NoiseStreamer* icecastClient();
    NoiseStreamer* createNewIcecast();
    void disposeIcecast();
    void disposeIcecastClient();

protected:
	NoiseStreamerAgentProtocol* agentProtocol();
	NoiseStreamerAgentConfig* agentConfig();

	virtual ITcpProtocol* createProtocol();
	virtual string configFilename();
    virtual void loadConfig();
	virtual void initialize();
	virtual void startIcecast();
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

    friend void* icecast_agent_status(void* agent);
    friend void* icecast_now_playing(void* agent);
    friend void* icecast_start_client(void* agent);
    friend void* icecast_start(void* agent);
    friend void* icecast_stop_playing(void* agent);
    friend void* icecast_pause(void* agent);
    friend void* icecast_resume(void* agent);
    friend void* icecast_next_track(void* agent);
    friend void* icecast_stats_genre(void* agent);
    friend void* icecast_stats_artist(void* agent);

};

#endif // NoiseStreamerAgent_h__
