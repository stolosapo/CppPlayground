#include <iostream>
#include "TimeServiceFactory.h"
#include "TimeService.cpp"

TimeServiceFactory::TimeServiceFactory()
{

}

TimeServiceFactory::~TimeServiceFactory()
{

}

ITimeService *TimeServiceFactory::create()
{
	TimeService* srv = new TimeService;
	return (TimeService*) srv;
}