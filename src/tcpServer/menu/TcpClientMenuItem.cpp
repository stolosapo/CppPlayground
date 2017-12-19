#include "TcpClientMenuItem.h"

#include "../client/ITcpClient.h"
#include "../client/TcpClientFactory.h"

TcpClientMenuItem::TcpClientMenuItem(ILogService *logSrv) : MenuItem()
{
        this->logSrv = logSrv;

        this->setId(2);
        this->setName("Tcp Client");
        this->setTitle("Tcp Client");
        this->setDescription("The First Kube Tcp Client");
}

TcpClientMenuItem::~TcpClientMenuItem()
{

}

void TcpClientMenuItem::action()
{
        this->identify();
        this->logSrv->outString("\n\n");

        ITcpClient* client = TcpClientFactory::create(this->logSrv);

        client->action();
}
