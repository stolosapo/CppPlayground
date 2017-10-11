#include "IcecastClientMenuItem.h"

#include "../IcecastClient.h"

#include "../../lib/excecutor/Excecutor.h"

#include "../../lib/exception/domain/DomainException.h"
#include "../exception/IcecastDomainErrorCode.h"


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

void IcecastClientMenuItem::check()
{
#ifndef ICECAST
	throw DomainException(IcecastDomainErrorCode::ICS0001);
#endif
}

void IcecastClientMenuItem::action()
{
    IcecastClient* client = new IcecastClient(this->logSrv);

    client->action();

    delete client;
}
