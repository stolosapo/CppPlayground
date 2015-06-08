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
		cout << message;
	}

	void printl(string message)
	{
		cout << message << endl;
	}

	void info(string message)
	{
		cout << " *** [ INFO ]: " << message << endl;
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
		cout<<"Hello World!!"<<endl;
	}
};