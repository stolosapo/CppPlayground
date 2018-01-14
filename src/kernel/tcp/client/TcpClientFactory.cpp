#include "TcpClientFactory.h"

#include "../../log/ILogService.h"
#include "../../di/GlobalAppContext.h"
#include "../../interruption/SignalService.h"

#include "TcpClient.h"


TcpClientFactory::TcpClientFactory()
{

}

TcpClientFactory::~TcpClientFactory()
{

}

ITcpClient *TcpClientFactory::create(ILogService *logSrv)
{
	SignalService* sigSrv = inject<SignalService>("signalService");

	TcpClient* srv = new TcpClient(logSrv, sigSrv);

	return (ITcpClient*) srv;
}
