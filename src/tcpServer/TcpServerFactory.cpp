#include "TcpServerFactory.h"
#include "SimpleTcpServer.h"
#include "TcpServer.h"

TcpServerFactory::TcpServerFactory()
{

}

TcpServerFactory::~TcpServerFactory()
{

}

ITcpServer *TcpServerFactory::create(ILogService *logSrv)
{
	// SimpleTcpServer* srv = new SimpleTcpServer(logSrv);

	TcpServer* srv = new TcpServer(logSrv);
	return (ITcpServer*) srv;
}