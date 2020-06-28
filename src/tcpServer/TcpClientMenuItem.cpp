#include "TcpClientMenuItem.h"

#include "../kernel/tcp/client/ITcpClient.h"
#include "../kernel/tcp/client/TcpClientFactory.h"
#include "../kernel/console/Console.h"

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
    Console::outStringln("\n");

    ITcpClient* client = TcpClientFactory::create(this->logSrv);

    client->action();
}
