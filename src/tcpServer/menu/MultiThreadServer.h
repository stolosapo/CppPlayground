#ifndef MultiThreadServer_h__
#define MultiThreadServer_h__

#include <string>
#include "ITcpServer.h"
#include "../TcpAcceptor.h"
#include "../../log/ILogService.h"

using namespace std;

class MultiThreadServer : public ITcpServer
{
private:
	static const int DEFAULT_PORT = 51717;
	static const char* DEFAULT_HOSTNAME;

	ILogService *logSrv;

	int port;
	const char* hostname;

	TcpAcceptor *acceptor;

	bool allowClient(TcpStream* stream);
	void acceptNewClient(pthread_t clientThread, TcpStream* stream);

	bool handshake();
	
	void *task(void *);
	static void *taskHelper(void *context);

	void processCommand(TcpStream *stream, string command);

public:
	MultiThreadServer(ILogService *logSrv);
	virtual ~MultiThreadServer();

	virtual void start();
	virtual void action();
};

#endif // MultiThreadServer_h__