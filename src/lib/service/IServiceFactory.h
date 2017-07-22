#ifndef IServiceFactory_h__
#define IServiceFactory_h__

#include "IService.h"

class IServiceFactory
{
public:
	IServiceFactory();
	virtual ~IServiceFactory();

	virtual IService* create() = 0;

};

#endif // IServiceFactory_h__