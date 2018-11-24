#ifndef IcecastAgent_h__
#define IcecastAgent_h__

#include <string>

#include "IcecastClient.h"
#include "IcecastAgentArgumentAdapter.h"
#include "protocol/IcecastAgentProtocol.h"
#include "config/IcecastAgentConfig.h"

#include "../kernel/tcp/ClientInfo.h"
#include "../kernel/tcp/server/StatefullTcpServer.h"
#include "../kernel/interruption/SignalService.h"
#include "../kernel/time/ITimeService.h"
#include "../kernel/audio/AudioTagService.h"

using namespace std;

class IcecastAgent : public TcpServer, public IcecastAgentArgumentAdapter
{
private:
    AudioTagService *tagSrv;
    AudioEncodingService *encSrv;

	Thread* icecastThread;
	IcecastClient *icecast;

    IcecastClient* icecastClient();
    IcecastClient* createNewIcecast();
    void disposeIcecast();
    void disposeIcecastClient();

protected:
	IcecastAgentProtocol* agentProtocol();
	IcecastAgentConfig* agentConfig();

	virtual ITcpProtocol* createProtocol();
	virtual string configFilename();
    virtual void loadConfig();
	virtual void initialize();
	virtual void startIcecast();
	virtual bool validateCommand(string command);
	virtual void processCommand(ClientInfo *client, string command);

public:
	IcecastAgent(
        ILogService *logSrv,
        SignalService *sigSrv,
        ITimeService *timeSrv,
        AudioTagService *tagSrv,
        ArgumentService *argSrv,
        AudioEncodingService *encSrv);
	virtual ~IcecastAgent();

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

#endif // IcecastAgent_h__
