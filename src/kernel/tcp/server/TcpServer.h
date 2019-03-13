#ifndef TcpServer_h__
#define TcpServer_h__

#include <string>
#include "ITcpServer.h"
#include "../config/TcpServerConfig.h"
#include "../protocol/ITcpProtocol.h"
#include "../lib/TcpAcceptor.h"
#include "../ClientInfo.h"
#include "../../log/ILogService.h"
#include "../../task/ThreadPool.h"
#include "../../interruption/SignalService.h"
#include "../../time/ITimeService.h"

using namespace std;

class TcpServer : public ITcpServer
{
private:
	ITcpProtocol *protocol;
	TcpAcceptor *acceptor;
	ThreadPool* pool;

	time_t startTime;

	void* task(void*);
	static void* internalClientTask(void *context);

	Thread* getNextThread();
	void finalizeClient(ClientInfo *client);

public:
    ITimeService* timeSrv;

	TcpServer(ILogService *logSrv, SignalService *sigSrv, ITimeService* timeSrv);
	virtual ~TcpServer();

	ILogService* logger();

	virtual void start();
	virtual void action();

	virtual double uptime();
	virtual int numberOfActiveConnections();

protected:
    SignalService* sigSrv;
    ILogService *logSrv;

	TcpServerConfig* config;

	ITcpProtocol* getProtocol();

	virtual ITcpProtocol* createProtocol();
	virtual string configFilename();
	virtual void loadConfig();
	virtual void initialize();

	virtual void cycle(ClientInfo *client, string input);

	virtual bool validateCommand(string command);
	virtual void processCommand(ClientInfo *client, string command);
	virtual void processErrorCommand(ClientInfo *client, string command);
};

#endif // TcpServer_h__
