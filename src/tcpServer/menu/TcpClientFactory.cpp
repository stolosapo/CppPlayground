#include "ITcpClient.h"
#include "TcpClient.h"
#include "../../log/ILogService.h"

class TcpClientFactory
{
public:
	TcpClientFactory()
	{

	}

	~TcpClientFactory()
	{

	}
	
	static ITcpClient *create(ILogService *logSrv)
	{
		TcpClient* srv = new TcpClient(logSrv);
		return (ITcpClient*) srv;
	}
};