#ifndef LogService_h__
#define LogService_h__

#include <iostream>
#include <string>

#include "ILogService.h"

using namespace std;

class LogService : public ILogService
{
public:
	LogService();
	virtual ~LogService();

	virtual void trace(string message) = 0;
	virtual void info(string message) = 0;
	virtual void debug(string message) = 0;
	virtual void warn(string message) = 0;
	virtual void error(string message) = 0;
	virtual void fatal(string message) = 0;

};

#endif // LogService_h__
