#ifndef TcpServer_h__
#define TcpServer_h__

#include <string>
#include "ITcpServer.h"
#include "../config/TcpServerConfig.h"
#include "../protocol/ITcpProtocol.h"
#include "../lib/TcpAcceptor.h"
#include "../ClientInfo.h"
#include "../../kernel/log/ILogService.h"
#include "../../kernel/task/ThreadPool.h"

using namespace std;

class TcpServer : public ITcpServer
{
private:
	ITcpProtocol *protocol;
	TcpAcceptor *acceptor;
	TcpServerConfig* config;
	ThreadPool* pool;

	ILogService *logSrv;

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
	ILogService* logger();

	virtual void loadConfig();
	virtual void initialize();

	virtual void cycle(ClientInfo *client, string input);

	virtual bool validateCommand(string command);
	virtual void processCommand(ClientInfo *client, string command);
	virtual void processErrorCommand(ClientInfo *client, string command);
};

#endif // TcpServer_h__
