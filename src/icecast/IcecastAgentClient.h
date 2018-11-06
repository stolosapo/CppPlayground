#ifndef IcecastAgentClient_h__
#define IcecastAgentClient_h__

#include <string>

#include "IcecastAgentClientArgumentAdapter.h"

#include "../kernel/tcp/ClientInfo.h"
#include "../kernel/tcp/client/TcpClient.h"
#include "../kernel/interruption/SignalService.h"

using namespace std;

class IcecastAgentClient : public TcpClient, public IcecastAgentClientArgumentAdapter
{
protected:
	virtual ITcpProtocol* createProtocol();
	virtual string configFilename();

public:
	IcecastAgentClient(ILogService *logSrv, SignalService *sigSrv, ArgumentService *argSrv);
	virtual ~IcecastAgentClient();

};

#endif // IcecastAgentClient_h__
