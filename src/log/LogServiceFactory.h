#ifndef LogServiceFactory_h__
#define LogServiceFactory_h__

#include "ILogService.h"
#include "../kernel/service/IService.h"
#include "../kernel/service/IServiceFactory.h"

class LogServiceFactory: public IServiceFactory
{
public:
	LogServiceFactory();
	virtual ~LogServiceFactory();
	
	IService *create();
};

#endif // #ifndef LogServiceFactory_h__