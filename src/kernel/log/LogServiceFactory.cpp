#include "LogServiceFactory.h"
#include "LogConsoleService.cpp"

#include "../di/GlobalAppContext.h"
#include "../time/ITimeService.h"
#include "LogService.h"

LogServiceFactory::LogServiceFactory(): IServiceFactory()
{

}

LogServiceFactory::~LogServiceFactory()
{

}

IService *LogServiceFactory::create()
{
	// LogConsoleService* srv = new LogConsoleService;

    ITimeService* timeService = inject<ITimeService>("timeService");
    LogService * srv = new LogService(timeService);
    srv->init();

    return (IService*) srv;
}
