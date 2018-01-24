#include "IcecastClientMenuItem.h"

#include "../IcecastClient.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../exception/IcecastDomainErrorCode.h"

#include "../../audio/mp3/Mp3Id3v2.h"


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
	// Mp3Id3v2 mp3;
	// mp3.action();

	IcecastClient* client = new IcecastClient(this->logSrv);
	
	client->action();
	
	delete client;
}
