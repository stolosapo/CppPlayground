#ifndef ILogService_h__
#define ILogService_h__

#include <iostream>
#include <string>

#include "../service/IService.h"

using namespace std;

class ILogService : public IService
{
public:
	ILogService(): IService() { };
	virtual ~ILogService() { };

	virtual void trace(string message) = 0;
	virtual void info(string message) = 0;
	virtual void debug(string message) = 0;
	virtual void warn(string message) = 0;
	virtual void error(string message) = 0;
	virtual void fatal(string message) = 0;

};

#endif // ILogService_h__
