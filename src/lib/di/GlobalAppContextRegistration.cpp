#include "GlobalAppContextRegistration.h"
#include "GlobalAppContext.h"

#include "../../log/LogServiceFactory.h"
#include "../../serialization/SerializationServiceFactory.h"

void registerServices()
{
	/* Logging Service */
	registerGlobalService<LogServiceFactory>(SINGLETON, "logService", new LogServiceFactory);

	/* Serialization Service */
	registerGlobalService<SerializationServiceFactory>(SINGLETON, "serializationService", new SerializationServiceFactory);
}
