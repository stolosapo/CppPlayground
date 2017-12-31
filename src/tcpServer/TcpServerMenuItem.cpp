#include "TcpServerMenuItem.h"

#include "../kernel/tcp/server/ITcpServer.h"
#include "../kernel/tcp/server/TcpServerFactory.h"
#include "../kernel/tcp/server/TestStatefullTcpServer.h"

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

        ITcpServer* server = new TestStatefullTcpServer(this->logSrv);

        server->action();

        delete server;
}
