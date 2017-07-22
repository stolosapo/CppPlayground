#ifndef AppContextScope_h__
#define AppContextScope_h__

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
void registerServices();

IService* inject(string serviceName);


#endif // AppContextScope_h__