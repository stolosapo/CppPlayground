#ifndef IcecastAgentClient_h__
#define IcecastAgentClient_h__

#include <string>

#include "../kernel/tcp/ClientInfo.h"
#include "../kernel/tcp/client/TcpClient.h"
#include "../kernel/interruption/SignalService.h"

using namespace std;

class IcecastAgentClient : public TcpClient
{
protected:
	virtual ITcpProtocol* createProtocol();
	virtual const char* configFilename();

public:
	IcecastAgentClient(ILogService *logSrv, SignalService *sigSrv);
	virtual ~IcecastAgentClient();
	
};

#endif // IcecastAgentClient_h__
