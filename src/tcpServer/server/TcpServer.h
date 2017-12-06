#ifndef TcpServer_h__
#define TcpServer_h__

#include <string>
#include "ITcpServer.h"
#include "../config/TcpServerConfig.h"
#include "../lib/TcpAcceptor.h"
#include "../ClientInfo.h"
#include "../../log/ILogService.h"
#include "../../lib/task/ThreadPool.h"

using namespace std;

class TcpServer : public ITcpServer
{
private:
	ILogService *logSrv;

	TcpAcceptor *acceptor;
	TcpServerConfig* config;
	ThreadPool* pool;

	bool allowClient(ClientInfo *client);

	void* task(void*);
	static void* taskHelper(void *context);

	Thread* getNextThread();
	void finalizeClient(ClientInfo *client);

public:
	TcpServer(ILogService *logSrv);
	virtual ~TcpServer();

	virtual void start();
	virtual void action();

protected:
	virtual void loadConfig();
	virtual void initialize();

	virtual bool handshake();
	virtual bool validateCommand(string command);
	virtual void processCommand(ClientInfo *client, string command);
};

#endif // TcpServer_h__
