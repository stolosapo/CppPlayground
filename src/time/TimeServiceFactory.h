#ifndef TimeServiceFactory_h__
#define TimeServiceFactory_h__

#include <iostream>
#include "ITimeService.h"
#include "../lib/service/IServiceFactory.h"

class TimeServiceFactory: public IServiceFactory
{
public:
	TimeServiceFactory();
	~TimeServiceFactory();

	IService *create();
};

#endif // #ifndef TimeServiceFactory_h__
