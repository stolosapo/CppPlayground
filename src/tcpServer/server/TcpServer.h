#ifndef TcpServer_h__
#define TcpServer_h__

#include <string>
#include "ITcpServer.h"
#include "../config/TcpServerConfig.h"
#include "../protocol/ITcpProtocol.h"
#include "../lib/TcpAcceptor.h"
#include "../ClientInfo.h"
#include "../../log/ILogService.h"
#include "../../lib/task/ThreadPool.h"

using namespace std;

class TcpServer : public ITcpServer
{
private:
	ILogService *logSrv;

	ITcpProtocol *protocol;
	TcpAcceptor *acceptor;
	TcpServerConfig* config;
	ThreadPool* pool;

	void* task(void*);
	static void* internalClientTask(void *context);

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

	virtual void cycle(ClientInfo *client, string input);

	virtual bool validateCommand(string command);
	virtual void processCommand(ClientInfo *client, string command);
};

#endif // TcpServer_h__
