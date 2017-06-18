#include "IcecastClientMenuItem.h"

#include "../IcecastClient.h"


IcecastClientMenuItem::IcecastClientMenuItem(ILogService *logSrv) : MenuItem()
{
	this->logSrv = logSrv;

	this->setId(1);

	this->setName("Icecast Client");
	this->setTitle("Icecast Client");
}

IcecastClientMenuItem::~IcecastClientMenuItem()
{
	
}

void IcecastClientMenuItem::action()
{
    IcecastClient* client = new IcecastClient(this->logSrv);

    client->action();

    delete client;
}