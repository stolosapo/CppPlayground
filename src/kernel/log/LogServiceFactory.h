#ifndef LogServiceFactory_h__
#define LogServiceFactory_h__

#include "ILogService.h"
#include "../service/IService.h"
#include "../service/IServiceFactory.h"

class LogServiceFactory: public IServiceFactory
{
public:
	LogServiceFactory();
	virtual ~LogServiceFactory();
	
	IService *create();
};

#endif // #ifndef LogServiceFactory_h__