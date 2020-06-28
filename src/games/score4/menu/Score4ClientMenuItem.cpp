#include "Score4ClientMenuItem.h"

#include "../client/Score4Client.h"
#include "../../../kernel/di/GlobalAppContext.h"
#include "../../../kernel/interruption/SignalService.h"
#include "../../../kernel/console/Console.h"

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
	this->identify();
	Console::outStringln("\n");

	SignalService* sigSrv = inject<SignalService>("signalService");

	Score4Client client(logSrv, sigSrv);

	client.action();
}
