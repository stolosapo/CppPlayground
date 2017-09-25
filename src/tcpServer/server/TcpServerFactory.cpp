#include "TcpServerFactory.h"

#include "TcpServer.h"
#include "MultiThreadServer.h"


TcpServerFactory::TcpServerFactory()
{

}

TcpServerFactory::~TcpServerFactory()
{

}

ITcpServer *TcpServerFactory::create(ILogService *logSrv, bool multiThread)
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
