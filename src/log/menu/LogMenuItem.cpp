#include "LogMenuItem.h"

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
	logSrv->outString("Type a messege to test: ");
	string message = logSrv->inString();
	logSrv->outString("\n\n");

	logSrv->print(message);
	logSrv->printl("");

	logSrv->info(message);
	logSrv->printl("");

	logSrv->debug(message);
	logSrv->printl("");

	logSrv->error(message);
	logSrv->printl("");

	logSrv->fatal(message);
	logSrv->printl("");

	logSrv->test();
	logSrv->printl("");
}
