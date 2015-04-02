#ifndef ILogService_h__
#define ILogService_h__

#include <iostream>
#include <string>

using namespace std;

class ILogService
{
public:
	ILogService() { };
	virtual ~ILogService() { };
	
	virtual void info(string message) = 0;
	virtual void debug(string message) = 0;
	virtual void error(string message) = 0;
	virtual void fatal(string message) = 0;
	virtual void test() = 0;
};

#endif // ILogService_h__