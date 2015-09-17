#include <iostream>
#include <string>
#include "ILogService.h"
#include "LogActionItem.h"
#include "../shared/convert.h"
#include "../menu/MenuItem.h"

using namespace std;

LogActionItem::LogActionItem(ILogService *logSrv) : MenuItem()
{
	this->logSrv = logSrv;

	this->setId(1);

	this->setName("Test Logging Service");
	this->setTitle("Test Logging Service");
}

LogActionItem::~LogActionItem()
{
	
}

void LogActionItem::action()
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