#include "SerializationServiceFactory.h"
#include "json/JzonService.cpp"

SerializationServiceFactory::SerializationServiceFactory() 
{

}

ISerializationService *SerializationServiceFactory::create()
{
	JzonService* srv = new JzonService;
	return  (ISerializationService*) srv;
}