#ifndef ILogService_h__
#define ILogService_h__

#include <iostream>
#include <string>

#include "../lib/service/IService.h"
#include "../lib/io/InOut.h"

using namespace std;

class ILogService : public IService, public InOut
{
protected:
	bool useColor;

public:
	ILogService(): IService(), InOut() { };
	virtual ~ILogService() { };

	bool getUseColor();
	void setUseColor(bool useColor);
	
	virtual void clearScreen() = 0;
	
	virtual void print(string message) = 0;
	virtual void print(string message, string COLOR) = 0;
	virtual void printl(string message) = 0;
	virtual void printColor(string message) = 0;

	virtual void info(string message) = 0;
	virtual void debug(string message) = 0;
	virtual void error(string message) = 0;
	virtual void fatal(string message) = 0;
	
	virtual void test() = 0;
};

#endif // ILogService_h__