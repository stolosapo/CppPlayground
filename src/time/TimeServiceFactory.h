#ifndef TimeServiceFactory_h__
#define TimeServiceFactory_h__

#include <iostream>
#include "ITimeService.h"

class TimeServiceFactory
{
public:
	TimeServiceFactory();
	~TimeServiceFactory();
	
	static ITimeService *create();
};

#endif // #ifndef TimeServiceFactory_h__