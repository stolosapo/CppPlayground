#include "GlobalAppContext.h"
#include "GlobalAppContextRegistration.h"

#include <map>

#include "InjectionScope.h"

void initializeAppContext()
{
	/* Create context */
	appContext = new AppContext;

	/* register all services */
	registerServices();

	/* load START_UP services */
	loadStartupServices();
}

void deleteAppContext()
{
	delete appContext;
}

void loadStartupServices()
{
	map<string, InjectionScope> scopes = appContext->getScopes();

	for (map<string, InjectionScope>::iterator it = scopes.begin(); 
		it != scopes.end(); 
		++it)
	{
		string curServiceName = it->first;
		InjectionScope curScope = it->second;

		if (curScope == START_UP)
		{
			appContext->getService(curServiceName);
		}
	}
}

IService* inject(string serviceName)
{
	return appContext->getService(serviceName);
}