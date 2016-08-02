#ifndef SerializationServiceFactory_h__
#define SerializationServiceFactory_h__

#include <iostream>
#include "ISerializationService.h"

class SerializationServiceFactory
{
public:
	SerializationServiceFactory();

	static ISerializationService *create();
};


#endif // SerializationServiceFactory_h__