#ifndef ILogService_h__
#define ILogService_h__

#include <iostream>

class ILogService
{
public:
	ILogService() { };
	virtual ~ILogService() { };
	
	virtual void test() = 0;
};

#endif // ILogService_h__