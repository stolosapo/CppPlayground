#include "Score4ServerMenuItem.h"

#include "../server/Score4Server.h"

Score4ServerMenuItem::Score4ServerMenuItem(ILogService *logSrv) : MenuItem()
{
	this->logSrv = logSrv;

	this->setId(1);
	this->setName("Server");
	this->setTitle("Server");
	this->setDescription("Start new Score 4 server");
}

Score4ServerMenuItem::~Score4ServerMenuItem()
{

}

void Score4ServerMenuItem::action()
{
	this->identify();
	this->logSrv->outString("\n\n");

	Score4Server server(this->logSrv);

	server.action();
}
