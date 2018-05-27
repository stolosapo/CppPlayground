#include "TcpServerFactory.h"

#include "TcpServer.h"
#include "../../di/GlobalAppContext.h"
#include "../../interruption/SignalService.h"
#include "../../time/ITimeService.h"

TcpServerFactory::TcpServerFactory()
{

}

TcpServerFactory::~TcpServerFactory()
{

}

ITcpServer *TcpServerFactory::create(ILogService *logSrv)
{
	SignalService* sigSrv = inject<SignalService>("signalService");
	ITimeService* timeSrv = inject<ITimeService>("timeService");

	TcpServer* srv = new TcpServer(logSrv, sigSrv, timeSrv);

	return (ITcpServer*) srv;
}
