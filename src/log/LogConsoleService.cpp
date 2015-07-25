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

	void info(string message)
	{
		outString(" *** [ INFO ]: ");
		outString(message);
		outString("\n");

		// cout << " *** [ INFO ]: " << message << endl;
	}

	void debug(string message)
	{
		cout << " *** [ DEBUG ]: " << message << endl;	
	}

	void error(string message)
	{
		cout << " *** [ ERROR ]: " << message << endl;	
	}

	void fatal(string message)
	{
		cout << " *** [ FATAL ]: " << message << endl;	
	}

	void test() 
	{
		outString("Hello World!!");
		// cout<<"Hello World!!"<<endl;
	}
};