#include "TcpServerFactory.h"

#include "TcpServer.h"
#include "../../di/GlobalAppContext.h"
#include "../../interruption/SignalService.h"

TcpServerFactory::TcpServerFactory()
{

}

TcpServerFactory::~TcpServerFactory()
{

}

ITcpServer *TcpServerFactory::create(ILogService *logSrv)
{
	SignalService* sigSrv = inject<SignalService>("signalService");

	TcpServer* srv = new TcpServer(logSrv, sigSrv);

	return (ITcpServer*) srv;
}
