#include "SignalServiceFactory.h"

SignalServiceFactory::SignalServiceFactory()
{

}

SignalServiceFactory::~SignalServiceFactory()
{

}

IService* SignalServiceFactory::create()
{
	SignalService* srv = new SignalService();

	srv->registerSignals();
	srv->setup();

	return (IService*) srv;
}