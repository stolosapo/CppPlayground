#include "SerializationServiceFactory.h"
#include "json/JzonService.h"

SerializationServiceFactory::SerializationServiceFactory()
{

}

IService *SerializationServiceFactory::create()
{
	JzonService* srv = new JzonService;
	return  (IService*) srv;
}
