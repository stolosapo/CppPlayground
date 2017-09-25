#include "ITcpServer.h"
#include "TcpServer.h"
#include "MultiThreadServer.h"
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
	
	static ITcpServer *create(ILogService *logSrv, bool multiThread)
	{
		if (!multiThread)
		{
			TcpServer* srv = new TcpServer(logSrv);
			return (ITcpServer*) srv;
		}
		else
		{
			MultiThreadServer* srv = new MultiThreadServer(logSrv);
			return (ITcpServer*) srv;
		}
	}
};