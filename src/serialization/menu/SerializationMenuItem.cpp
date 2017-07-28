#include "SerializationMenuItem.h"
#include "../SerializationServiceFactory.h"

#include "../../lib/di/GlobalAppContext.h"

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
