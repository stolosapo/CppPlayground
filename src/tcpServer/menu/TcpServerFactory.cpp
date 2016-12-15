#include "ITcpServer.h"
#include "TcpServer.h"
#include "../../log/ILogService.h"

class TcpServerFactory
{
public:
	TcpServerFactory()
	{

	}

	~TcpServerFactory()
	{

	}
	
	static ITcpServer *create(ILogService *logSrv)
	{
		TcpServer* srv = new TcpServer(logSrv);
		return (ITcpServer*) srv;
	}
};