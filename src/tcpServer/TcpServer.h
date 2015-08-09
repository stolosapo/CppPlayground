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
	TcpServer(ILogService *logSrv);
	virtual ~TcpServer();

	int getPort();
	bool isActive();

	void setPort(int port);

	void start();
	virtual void action();
};

#endif // TcpServer_h__