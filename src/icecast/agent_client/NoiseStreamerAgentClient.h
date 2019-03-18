#ifndef NoiseStreamerAgentClient_h__
#define NoiseStreamerAgentClient_h__

#include <string>

#include "NoiseStreamerAgentClientArgumentAdapter.h"

#include "../../kernel/tcp/ClientInfo.h"
#include "../../kernel/tcp/client/TcpClient.h"
#include "../../kernel/interruption/SignalService.h"

using namespace std;

class NoiseStreamerAgentClient : public TcpClient, public NoiseStreamerAgentClientArgumentAdapter
{
protected:
	virtual ITcpProtocol* createProtocol();
	virtual string configFilename();

public:
	NoiseStreamerAgentClient(ILogService *logSrv, SignalService *sigSrv, ArgumentService *argSrv);
	virtual ~NoiseStreamerAgentClient();

};

#endif // NoiseStreamerAgentClient_h__
