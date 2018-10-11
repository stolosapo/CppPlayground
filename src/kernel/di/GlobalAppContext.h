#ifndef GlobalAppContext_h__
#define GlobalAppContext_h__

#include <iostream>
#include <string>

#include "AppContext.h"
#include "../service/IService.h"

using namespace std;


/* Global AppContext */
extern AppContext appContext;


/* Context initialization */
void initializeAppContext(int argc, char* argv[]);
void deleteAppContext();


/* Context methods */
void loadStartupServices();

template<class T>
void registerGlobalService(InjectionScope scope, string serviceName, T* serviceFactory);

template<class T>
T* inject(string serviceName);





/**
	IMPLEMENTATIONS
*/

template<class T>
void registerGlobalService(InjectionScope scope, string serviceName, T* serviceFactory)
{
	appContext.registerService(scope, serviceName, (IServiceFactory*) serviceFactory);

	cout << "* Factory for service: '" << serviceName << "' registed in appContext." << endl;
}


template<class T>
T* inject(string serviceName)
{
	IService* srv = appContext.getService(serviceName);
	return (T*) srv;
}

#endif // GlobalAppContext_h__
