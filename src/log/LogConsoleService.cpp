#include <iostream>
#include "ILogService.h"

using namespace std;

class LogConsoleService : public ILogService
{
public:
	LogConsoleService()
	{

	}
	
	~LogConsoleService()
	{

	}

	void test() 
	{
		cout<<"Hello World!!"<<endl;
	}
};