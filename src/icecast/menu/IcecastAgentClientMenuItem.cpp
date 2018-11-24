#include "IcecastAgentClientMenuItem.h"

#include "../IcecastAgentClient.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../exception/IcecastDomainErrorCode.h"

#include "../../kernel/di/GlobalAppContext.h"
#include "../../kernel/interruption/SignalService.h"
#include "../../kernel/arguments/ArgumentService.h"


IcecastAgentClientMenuItem::IcecastAgentClientMenuItem(ILogService *logSrv) : MenuItem()
{
	this->logSrv = logSrv;

	this->setId(3);

	this->setName("Icecast Agent Client");
	this->setTitle("Icecast Agent Client");
}

IcecastAgentClientMenuItem::~IcecastAgentClientMenuItem()
{

}

void IcecastAgentClientMenuItem::check()
{
#ifndef ICECAST
	throw DomainException(IcecastDomainErrorCode::ICS0001);
#endif
}

IcecastAgentClient* IcecastAgentClientMenuItem::clientFactory()
{
    SignalService* sigSrv = inject<SignalService>("signalService");
    ArgumentService* argSrv = inject<ArgumentService>("argService");

	IcecastAgentClient* client = new IcecastAgentClient(this->logSrv, sigSrv, argSrv);

    return client;
}

void IcecastAgentClientMenuItem::action()
{
	IcecastAgentClient* client = clientFactory();

	client->action();

    delete client;
}

string IcecastAgentClientMenuItem::help()
{
    IcecastAgentClient* client = clientFactory();

    client->registerArguments();
    string hh = client->help();

    delete client;

    return hh;
}
