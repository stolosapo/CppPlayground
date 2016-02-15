#ifndef TcpServer_h__
#define TcpServer_h__

#include <string>
#include "ITcpServer.h"
#include "TcpAcceptor.h"
#include "../log/ILogService.h"

using namespace std;

class TcpServer : public ITcpServer
{
private:
	static const int DEFAULT_PORT = 51717;
	static const char* DEFAULT_HOSTNAME;

	ILogService *logSrv;

	int port;
	const char* hostname;

	TcpAcceptor *acceptor;
	TcpStream *stream;

	bool acceptClient();
	bool handshake();
	void processCommand(TcpStream *stream, string command);

public:
	TcpServer(ILogService *logSrv);
	virtual ~TcpServer();

	virtual void start();
	virtual void action();
};

#endif // TcpServer_h__