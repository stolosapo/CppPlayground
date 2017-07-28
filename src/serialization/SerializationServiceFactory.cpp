#include "SerializationServiceFactory.h"
#include "json/JzonService.h"

SerializationServiceFactory::SerializationServiceFactory()
{

}

ISerializationService *SerializationServiceFactory::create()
{
	JzonService* srv = new JzonService;
	return  (ISerializationService*) srv;
}
