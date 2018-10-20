#include "GlobalAppContextRegistration.h"
#include "GlobalAppContext.h"

#include "../arguments/ArgumentServiceFactory.h"
#include "../log/LogServiceFactory.h"
#include "../time/TimeServiceFactory.h"
#include "../serialization/SerializationServiceFactory.h"
#include "../interruption/SignalServiceFactory.h"
#include "../audio/AudioTagServiceFactory.h"
#include "../audio/encoding/AudioEncodingServiceFactory.h"

void registerServices(int argc, char* argv[])
{
    /* Argument Service */
    registerGlobalService<ArgumentServiceFactory>(SINGLETON, "argService", new ArgumentServiceFactory(argc, argv));

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

    /* AudioEncoding Service */
    registerGlobalService<AudioEncodingServiceFactory>(SINGLETON, "audioEncodingService", new AudioEncodingServiceFactory);
}
