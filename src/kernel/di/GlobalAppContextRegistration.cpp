#include "GlobalAppContextRegistration.h"
#include "GlobalAppContext.h"

#include "../log/LogServiceFactory.h"
#include "../time/TimeServiceFactory.h"
#include "../serialization/SerializationServiceFactory.h"
#include "../interruption/SignalServiceFactory.h"
#include "../audio/AudioTagServiceFactory.h"

void registerServices()
{
	/* Logging Service */
	registerGlobalService<LogServiceFactory>(SINGLETON, "logService", new LogServiceFactory);

	/* Time Service */
	registerGlobalService<TimeServiceFactory>(SINGLETON, "timeService", new TimeServiceFactory);

	/* Serialization Service */
	registerGlobalService<SerializationServiceFactory>(SINGLETON, "serializationService", new SerializationServiceFactory);

	/* Signal Service */
	registerGlobalService<SignalServiceFactory>(START_UP, "signalService", new SignalServiceFactory);

	/* AudioTag Service */
	registerGlobalService<AudioTagServiceFactory>(SINGLETON, "audioTagService", new AudioTagServiceFactory);
}
