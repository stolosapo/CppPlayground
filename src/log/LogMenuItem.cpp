#include "LogMenuItem.h"

#include "../kernel/console/Console.h"

LogMenuItem::LogMenuItem(ILogService *logSrv) : MenuItem()
{
	this->logSrv = logSrv;

	this->setId(1);

	this->setName("Test Logging Service");
	this->setTitle("Test Logging Service");
}

LogMenuItem::~LogMenuItem()
{

}

void LogMenuItem::action()
{
	Console::outString("Type a messege to test: ");
	string message = Console::inString();
	Console::outStringln("");
	Console::outStringln("");

	Console::outStringln(message);

	logSrv->trace(message);
	Console::outStringln("");

	logSrv->info(message);
    Console::outStringln("");

	logSrv->debug(message);
	Console::outStringln("");

	logSrv->warn(message);
	Console::outStringln("");

	logSrv->error(message);
	Console::outStringln("");

	logSrv->fatal(message);
	Console::outStringln("");
}
