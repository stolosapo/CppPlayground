#ifndef JsonServiceFactory_h__
#define JsonServiceFactory_h__

#include <iostream>
#include "IJsonService.h"

class JsonServiceFactory
{
public:
	JsonServiceFactory();

	static IJsonService *create();
};


#endif // JsonServiceFactory_h__