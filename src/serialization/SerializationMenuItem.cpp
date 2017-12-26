#include "SerializationMenuItem.h"

#include "../kernel/serialization/SerializationServiceFactory.h"
#include "../kernel/di/GlobalAppContext.h"

SerializationMenuItem::SerializationMenuItem(ILogService *logSrv) : MenuItem()
{
	this->logSrv = logSrv;

	this->setId(1);

	this->setName("Test Serialization Service");
	this->setTitle("Test Serialization Service");
}

SerializationMenuItem::~SerializationMenuItem()
{

}

void SerializationMenuItem::action()
{
	ISerializationService *srv = inject<ISerializationService>("serializationService");

	srv->test();
}
