#include "AppContextScope.h"

void initializeAppContext()
{
	appContext = new AppContext;
}

void deleteAppContext()
{
	delete appContext;
}

IService* inject(string serviceName)
{
	return appContext->getService(serviceName);
}

void registerServices()
{

}