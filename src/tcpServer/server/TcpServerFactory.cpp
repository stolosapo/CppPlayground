#include "TcpServerFactory.h"

#include "TcpServer.h"


TcpServerFactory::TcpServerFactory()
{

}

TcpServerFactory::~TcpServerFactory()
{

}

ITcpServer *TcpServerFactory::create(ILogService *logSrv)
{
	TcpServer* srv = new TcpServer(logSrv);
	return (ITcpServer*) srv;
}
