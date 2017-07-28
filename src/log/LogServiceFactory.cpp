#include "LogServiceFactory.h"
#include "LogConsoleService.cpp"

LogServiceFactory::LogServiceFactory(): IServiceFactory()
{

}

LogServiceFactory::~LogServiceFactory()
{

}

IService *LogServiceFactory::create()
{
	LogConsoleService* srv = new LogConsoleService;
	return (IService*) srv;
}