#include "TcpServerMenuItem.h"

#include "../kernel/tcp/server/ITcpServer.h"
#include "../kernel/tcp/server/TcpServerFactory.h"
#include "../kernel/tcp/server/TestStatefullTcpServer.h"
#include "../kernel/di/GlobalAppContext.h"
#include "../kernel/interruption/SignalService.h"
#include "../kernel/time/ITimeService.h"

TcpServerMenuItem::TcpServerMenuItem(ILogService *logSrv) : MenuItem()
{
        this->logSrv = logSrv;

        this->setId(1);
        this->setName("Tcp Server");
        this->setTitle("Tcp Server");
        this->setDescription("The First Kube Tcp Server");
}

TcpServerMenuItem::~TcpServerMenuItem()
{

}

void TcpServerMenuItem::action()
{
        this->identify();
        this->logSrv->outString("\n\n");

        // ITcpServer* server = TcpServerFactory::create(this->logSrv);

        SignalService* sigSrv = inject<SignalService>("signalService");
        ITimeService* timeSrv = inject<ITimeService>("timeService");

        ITcpServer* server = new TestStatefullTcpServer(this->logSrv, sigSrv, timeSrv);

        server->action();

        delete server;
}
