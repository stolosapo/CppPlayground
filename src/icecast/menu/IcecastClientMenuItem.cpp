#include "IcecastClientMenuItem.h"


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
    cout << "Alive!!" << endl;
}