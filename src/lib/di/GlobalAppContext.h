#ifndef GlobalAppContext_h__
#define GlobalAppContext_h__

#include <iostream>
#include <string>

#include "AppContext.h"

#include "../service/IService.h"

using namespace std;


/* Global AppContext */
static AppContext* appContext;


/* Context initialization */
void initializeAppContext();
void deleteAppContext();


/* Context methods */
void loadStartupServices();
IService* inject(string serviceName);


#endif // GlobalAppContext_h__