#include <iostream>
#include "LogServiceFactory.h"
#include "LogConsoleService.cpp"

LogServiceFactory::LogServiceFactory()
{

}

LogServiceFactory::~LogServiceFactory()
{

}

ILogService *LogServiceFactory::create()
{
	LogConsoleService* srv = new LogConsoleService;
	return (LogConsoleService*) srv;
}