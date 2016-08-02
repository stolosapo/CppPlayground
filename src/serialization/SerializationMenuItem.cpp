#include "SerializationMenuItem.h"
#include "SerializationServiceFactory.h"

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
	ISerializationService *srv = SerializationServiceFactory::create();

	srv->test();
}