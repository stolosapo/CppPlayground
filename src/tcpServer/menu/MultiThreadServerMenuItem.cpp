#include "MultiThreadServerMenuItem.h"

#include "../server/ITcpServer.h"
#include "../server/TcpServerFactory.h"

MultiThreadServerMenuItem::MultiThreadServerMenuItem(ILogService *logSrv) : MenuItem()
{
        this->logSrv = logSrv;

        this->setId(2);
	this->setName("Multi Thread Server");
	this->setTitle("Multi Thread Server");
        this->setDescription("The First Kube Multi Thread Server");
}

MultiThreadServerMenuItem::~MultiThreadServerMenuItem()
{

}

void MultiThreadServerMenuItem::action()
{
        this->identify();
        this->logSrv->outString("\n\n");

        ITcpServer* server = TcpServerFactory::create(this->logSrv, true);

        server->action();
}
