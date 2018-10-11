#include "GlobalAppContext.h"
#include "GlobalAppContextRegistration.h"

#include <map>

#include "InjectionScope.h"


AppContext appContext;


void initializeAppContext(int argc, char* argv[])
{
	/* Create context */
	appContext = AppContext();

	cout << "* Created appContext: " << &appContext << endl;


	/* register all services */
	registerServices(argc, argv);

	cout << "* Registered Services" << endl;

	/* load START_UP services */
	loadStartupServices();
}

void deleteAppContext()
{

}

void loadStartupServices()
{
	map<string, InjectionScope> scopes = appContext.getScopes();

	for (map<string, InjectionScope>::iterator it = scopes.begin();
		it != scopes.end();
		++it)
	{
		string curServiceName = it->first;
		InjectionScope curScope = it->second;

		if (curScope == START_UP)
		{
			appContext.getService(curServiceName);
		}
	}
}
