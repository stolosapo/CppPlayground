#include "TcpServerMenuItem.h"

#include "../server/ITcpServer.h"
#include "../server/TcpServerFactory.h"

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

        ITcpServer* server = TcpServerFactory::create(this->logSrv, false);

        server->action();
}
