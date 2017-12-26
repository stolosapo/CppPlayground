#include "GlobalAppContextRegistration.h"
#include "GlobalAppContext.h"

#include "../../log/LogServiceFactory.h"
#include "../time/TimeServiceFactory.h"
#include "../../serialization/SerializationServiceFactory.h"

void registerServices()
{
	/* Logging Service */
	registerGlobalService<LogServiceFactory>(SINGLETON, "logService", new LogServiceFactory);

	/* Time Service */
	registerGlobalService<TimeServiceFactory>(SINGLETON, "timeService", new TimeServiceFactory);

	/* Serialization Service */
	registerGlobalService<SerializationServiceFactory>(SINGLETON, "serializationService", new SerializationServiceFactory);
}
