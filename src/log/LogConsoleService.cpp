#include <iostream>
#include <string>
#include "ILogService.h"

using namespace std;

class LogConsoleService : public ILogService
{
public:
	LogConsoleService() : ILogService()
	{

	}
	
	~LogConsoleService()
	{

	}

	void print(string message)
	{
		outString(message);
	}

	void printl(string message)
	{
		outString(message);
		outString("\n");
	}

	void info(string message)
	{
		outString(" *** [ INFO ]: ");
		outString(message);
		outString("\n");
	}

	void debug(string message)
	{
		outString(" *** [ DEBUG ]: ");
		outString(message);
		outString("\n");
	}

	void error(string message)
	{
		outString(" *** [ ERROR ]: ");
		outString(message);
		outString("\n");
	}

	void fatal(string message)
	{
		outString(" *** [ FATAL ]: ");
		outString(message);
		outString("\n");
	}

	void test() 
	{
		outString("Hello World!!");
	}
};