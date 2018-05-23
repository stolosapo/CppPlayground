#ifndef IcecastAgent_h__
#define IcecastAgent_h__

#include <string>

#include "IcecastClient.h"
#include "protocol/IcecastAgentProtocol.h"

#include "../kernel/tcp/ClientInfo.h"
#include "../kernel/tcp/server/StatefullTcpServer.h"
#include "../kernel/interruption/SignalService.h"
#include "../kernel/audio/AudioTagService.h"

using namespace std;

class IcecastAgent : public TcpServer
{
private:
	Thread* icecastThread;
	IcecastClient *icecast;

protected:
	IcecastAgentProtocol* agentProtocol();

	virtual ITcpProtocol* createProtocol();
	virtual const char* configFilename();
	virtual void initialize();
	virtual void startIcecast();
	virtual bool validateCommand(string command);
	virtual void processCommand(ClientInfo *client, string command);

public:
	IcecastAgent(ILogService *logSrv, SignalService *sigSrv, AudioTagService *tagSrv);
	virtual ~IcecastAgent();

};

#endif // IcecastAgent_h__
