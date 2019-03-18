#ifndef IServiceFactory_h__
#define IServiceFactory_h__

#include <string>

#include "IService.h"

using namespace std;

class IServiceFactory
{
private:
	string implementationSelection;

public:
	IServiceFactory();
	IServiceFactory(string implementationSelection);
	virtual ~IServiceFactory();

	virtual IService* create() = 0;

};

#endif // IServiceFactory_h__