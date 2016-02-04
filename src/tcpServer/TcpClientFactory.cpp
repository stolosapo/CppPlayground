#include "TcpClientFactory.h"
#include "TcpClient.h"

TcpClientFactory::TcpClientFactory()
{

}

TcpClientFactory::~TcpClientFactory()
{

}

ITcpClient *TcpClientFactory::create(ILogService *logSrv)
{
	TcpClient* srv = new TcpClient(logSrv);
	return (ITcpClient*) srv;
}