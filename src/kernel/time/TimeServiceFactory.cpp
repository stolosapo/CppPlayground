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
	TimeService* srv = new TimeService;
	return (IService*) srv;
}
