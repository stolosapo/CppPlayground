#ifndef TcpServer_h__
#define TcpServer_h__

#include <iostream>
#include <string>
#include "../menu/MenuItem.h"
#include "../log/ILogService.h"

using namespace std;

class TcpServer : public MenuItem
{
private:
	ILogService *logSrv;

	bool isActive;

	void activate();
	void passivate();

public:
	TcpServer(ILogService *logSrv);
	virtual ~TcpServer();

	void start();
	virtual void action();
};

#endif // TcpServer_h__