#ifndef LogServiceFactory_h__
#define LogServiceFactory_h__

#include "ILogService.h"
#include "../lib/service/IService.h"
#include "../lib/service/IServiceFactory.h"

class LogServiceFactory: public IServiceFactory
{
public:
	LogServiceFactory();
	virtual ~LogServiceFactory();
	
	IService *create();
};

#endif // #ifndef LogServiceFactory_h__