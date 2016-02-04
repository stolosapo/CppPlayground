#ifndef TcpClient_h__
#define TcpClient_h__

#include <iostream>
#include <string>
#include "ITcpClient.h"
#include "../log/ILogService.h"

using namespace std;

class TcpClient : public ITcpClient
{
private:
	ILogService *logSrv;

	void test();
	void testConnect();

public:
	TcpClient(ILogService *logSrv);
	virtual ~TcpClient();

	virtual void action();
};

#endif // TcpClient_h__