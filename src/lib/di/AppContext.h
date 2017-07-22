#ifndef AppContext_h__
#define AppContext_h__

#include <iostream>
#include <string>
#include <map>

#include "../service/IService.h"
#include "../service/IServiceFactory.h"
#include "InjectionScope.h"

using namespace std;

class AppContext
{
private:
	/* All instatiated services */
	map<string, IService*> services;

	/* All registered factories */
	map<string, IServiceFactory*> serviceFactories;

	/* All scoped service */
	map<string, InjectionScope> scopes;

	bool serviceExists(string serviceName);
	bool factoryExists(string serviceName);
	bool scopeExists(string serviceName);

	IService* instantiateService(string serviceName);
	
	IService* getSingletonService(string serviceName);
	IService* getRequestedService(string serviceName);
	IService* getStartupService(string serviceName);


public:
	AppContext();
	virtual ~AppContext();

	map<string, InjectionScope> getScopes();

	void registerService(InjectionScope scope, string serviceName, IServiceFactory* serviceFactory);

	IService* getService(string serviceName);

};

#endif // AppContext_h__