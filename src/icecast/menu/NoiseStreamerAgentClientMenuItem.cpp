#include "NoiseStreamerAgentClientMenuItem.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../exception/NoiseStreamerDomainErrorCode.h"

#include "../../kernel/di/GlobalAppContext.h"
#include "../../kernel/interruption/SignalService.h"
#include "../../kernel/arguments/ArgumentService.h"


NoiseStreamerAgentClientMenuItem::NoiseStreamerAgentClientMenuItem(ILogService *logSrv) : MenuItem()
{
	this->logSrv = logSrv;

	this->setId(3);

	this->setName("Icecast Agent Client");
	this->setTitle("Icecast Agent Client");
}

NoiseStreamerAgentClientMenuItem::~NoiseStreamerAgentClientMenuItem()
{

}

void NoiseStreamerAgentClientMenuItem::check()
{
#ifndef ICECAST
	throw DomainException(NoiseStreamerDomainErrorCode::NSS0001);
#endif
}

NoiseStreamerAgentClient* NoiseStreamerAgentClientMenuItem::clientFactory()
{
    SignalService* sigSrv = inject<SignalService>("signalService");
    ArgumentService* argSrv = inject<ArgumentService>("argService");

	NoiseStreamerAgentClient* client = new NoiseStreamerAgentClient(this->logSrv, sigSrv, argSrv);

    return client;
}

void NoiseStreamerAgentClientMenuItem::action()
{
	NoiseStreamerAgentClient* client = clientFactory();

	client->action();

    delete client;
}

string NoiseStreamerAgentClientMenuItem::help()
{
    NoiseStreamerAgentClient* client = clientFactory();

    client->registerArguments();
    string hh = client->help();

    delete client;

    return hh;
}
