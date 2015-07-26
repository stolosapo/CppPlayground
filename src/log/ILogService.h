#ifndef ILogService_h__
#define ILogService_h__

#include <iostream>
#include <string>
#include "../shared/InOut.h"

using namespace std;

class ILogService : public InOut
{
public:
	ILogService()  : InOut() { };
	virtual ~ILogService() { };
	
	virtual void clearScreen() = 0;
	virtual void print(string message) = 0;
	virtual void printl(string message) = 0;
	virtual void info(string message) = 0;
	virtual void debug(string message) = 0;
	virtual void error(string message) = 0;
	virtual void fatal(string message) = 0;
	virtual void test() = 0;
};

#endif // ILogService_h__