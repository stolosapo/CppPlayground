#ifndef SerializationServiceFactory_h__
#define SerializationServiceFactory_h__

#include <iostream>
#include "ISerializationService.h"
#include "../service/IService.h"
#include "../service/IServiceFactory.h"

class SerializationServiceFactory: public IServiceFactory
{
public:
	SerializationServiceFactory();

	IService *create();
};


#endif // SerializationServiceFactory_h__
