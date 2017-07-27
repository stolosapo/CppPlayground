#include "GlobalAppContextRegistration.h"
#include "GlobalAppContext.h"

#include "../../log/LogServiceFactory.h"

void registerServices()
{
	registerGlobalService<LogServiceFactory>(SINGLETON, "logService", new LogServiceFactory);
}