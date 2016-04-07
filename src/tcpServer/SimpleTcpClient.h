#ifndef SimpleTcpClient_h__
#define SimpleTcpClient_h__

#include <iostream>
#include <string>
#include "ITcpClient.h"
#include "../log/ILogService.h"

using namespace std;

class SimpleTcpClient : public ITcpClient
{
private:
	ILogService *logSrv;

	void test();
	void testConnect();

public:
	SimpleTcpClient(ILogService *logSrv);
	virtual ~SimpleTcpClient();

	virtual void action();
};

#endif // SimpleTcpClient_h__