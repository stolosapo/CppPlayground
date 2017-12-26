#include "AppContext.h"


AppContext::AppContext()
{

}


AppContext::~AppContext()
{
	/* Clear scopes */
	scopes.clear();


	/* Clear service factories */
	for (map<string, IServiceFactory*>::iterator it = serviceFactories.begin(); 
		it != serviceFactories.end(); 
		++it)
	{
		delete it->second;
	}

	serviceFactories.clear();


	/* Clear singleton services */
	for (map<string, IService*>::iterator it = services.begin(); 
		it != services.end(); 
		++it)
	{
		delete it->second;
	}

	services.clear();
}


map<string, InjectionScope> AppContext::getScopes()
{
	return scopes;
}


void AppContext::registerService(InjectionScope scope, string serviceName, IServiceFactory* serviceFactory)
{
	/* First register service scope */
	scopes[serviceName] = scope;

	/* Then register factory */
	serviceFactories[serviceName] = serviceFactory;
}


bool AppContext::serviceExists(string serviceName)
{
	map<string, IService*>::iterator it;
	it = services.find(serviceName);

	return it != services.end();
}


bool AppContext::factoryExists(string serviceName)
{
	map<string, IServiceFactory*>::iterator it;
	it = serviceFactories.find(serviceName);

	return it != serviceFactories.end();
}


bool AppContext::scopeExists(string serviceName)
{
	map<string, InjectionScope>::iterator it;
	it = scopes.find(serviceName);

	return it != scopes.end();
}


IService* AppContext::instantiateService(string serviceName)
{
	IServiceFactory* factory = serviceFactories.find(serviceName)->second;

	IService* service = factory->create();

	services[serviceName] = service;

	return service;
}
	

IService* AppContext::getSingletonService(string serviceName)
{
	bool exists = serviceExists(serviceName);

	if (!exists)
	{
		return instantiateService(serviceName);
	}

	return services.find(serviceName)->second;
}


IService* AppContext::getRequestedService(string serviceName)
{
	return instantiateService(serviceName);
}


IService* AppContext::getStartupService(string serviceName)
{
	return instantiateService(serviceName);
}


IService* AppContext::getService(string serviceName)
{
	/* First get scope */
	InjectionScope scope = scopes.find(serviceName)->second;

	switch (scope)
	{
		case SINGLETON:
			return getSingletonService(serviceName);

		case REQUEST:
			return getRequestedService(serviceName);

		case START_UP:
			return getStartupService(serviceName);

		default:
			return getRequestedService(serviceName);			
	}
}