#ifndef LogServiceFactory_h__
#define LogServiceFactory_h__

#include "ILogService.h"

class LogServiceFactory
{
public:
	LogServiceFactory();
	~LogServiceFactory();
	
	static ILogService *create();
};

#endif // #ifndef LogServiceFactory_h__