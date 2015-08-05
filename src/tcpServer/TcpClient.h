#ifndef TcpClient_h__
#define TcpClient_h__

#include <iostream>
#include <string>
#include "../menu/MenuItem.h"
#include "../log/ILogService.h"

using namespace std;

class TcpClient : public MenuItem
{
private:
	ILogService *logSrv;

	void test();

public:
	TcpClient(ILogService *logSrv);
	virtual ~TcpClient();
;
	virtual void action();
};

#endif // TcpClient_h__