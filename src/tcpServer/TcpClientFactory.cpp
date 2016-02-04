#include "TcpClientFactory.h"
#include "SimpleTcpClient.h"
#include "TcpClient.h"

TcpClientFactory::TcpClientFactory()
{

}

TcpClientFactory::~TcpClientFactory()
{

}

ITcpClient *TcpClientFactory::create(ILogService *logSrv)
{
	// SimpleTcpClient* srv = new SimpleTcpClient(logSrv);

	TcpClient* srv = new TcpClient(logSrv);
	return (ITcpClient*) srv;
}