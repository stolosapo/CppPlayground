#include <iostream>
#include "TimeServiceFactory.h"
#include "TimeService.h"

TimeServiceFactory::TimeServiceFactory(): IServiceFactory()
{

}

TimeServiceFactory::~TimeServiceFactory()
{

}

IService *TimeServiceFactory::create()
{
	ITimeService* srv = (ITimeService*) new TimeService;
	return (IService*) srv;
}
