#include "Score4ClientMenuItem.h"

Score4ClientMenuItem::Score4ClientMenuItem(ILogService *logSrv) : MenuItem()
{
	this->logSrv = logSrv;

	this->setId(2);
	this->setName("Client");
	this->setTitle("Client");
	this->setDescription("Connect to a Score 4 session");
}

Score4ClientMenuItem::~Score4ClientMenuItem()
{

}

void Score4ClientMenuItem::action()
{

}
