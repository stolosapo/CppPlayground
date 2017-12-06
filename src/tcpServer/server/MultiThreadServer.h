#ifndef MultiThreadServer_h__
#define MultiThreadServer_h__

#include <string>
#include "ITcpServer.h"
#include "../config/TcpServerConfig.h"
#include "../lib/TcpAcceptor.h"
#include "../ClientInfo.h"
#include "../../log/ILogService.h"
#include "../../lib/task/ThreadPool.h"

using namespace std;

class MultiThreadServer : public ITcpServer
{
private:
	static const int DEFAULT_PORT = 51717;
	static const int DEFAULT_THREAD_POOL_SIZE = 5;
	static const char* DEFAULT_HOSTNAME;

	ILogService *logSrv;

	int port;
	string hostname;

	TcpAcceptor *acceptor;
	TcpServerConfig* config;

	ThreadPool* pool;

	bool allowClient(ClientInfo *client);

	void* task(void*);
	static void* taskHelper(void *context);

	Thread* getNextThread();
	void finalizeClient(ClientInfo *client);

public:
	MultiThreadServer(ILogService *logSrv);
	virtual ~MultiThreadServer();

	virtual void start();
	virtual void action();

protected:
	virtual void loadConfig();
	virtual void initialize();

	virtual bool handshake();
	virtual bool validateCommand(string command);
	virtual void processCommand(TcpStream *stream, string command);
};

#endif // MultiThreadServer_h__
