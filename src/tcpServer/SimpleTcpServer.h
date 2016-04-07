#ifndef SimpleTcpServer_h__
#define SimpleTcpServer_h__

#include <iostream>
#include "ITcpServer.h"
#include "../menu/MenuItem.h"
#include "../log/ILogService.h"

class SimpleTcpServer : public ITcpServer
{
private:
	static const int DEFAULT_PORT = 51717;

	ILogService *logSrv;

	int port;
	bool active;

	void activate();
	void passivate();

	int openSocket();
	int doBind();
	int listenSocket();
	int acceptConnection();
	int receive();
	int send();
	void test();

public:
	SimpleTcpServer(ILogService *logSrv);
	virtual ~SimpleTcpServer();

	int getPort();
	bool isActive();

	void setPort(int port);

	virtual void start();
	virtual void action();
};

#endif // SimpleTcpServer_h__