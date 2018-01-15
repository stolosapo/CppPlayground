#ifndef TestStatefullTcpServer_h__
#define TestStatefullTcpServer_h__

#include <string>

#include "StatefullTcpServer.h"
#include "TestState.h"
#include "../ClientInfo.h"

#include "../../exception/domain/DomainException.h"
#include "../../exception/ExceptionMapper.h"
#include "../../task/Locker.h"
#include "../../interruption/SignalService.h"

using namespace std;

class TestStatefullTcpServer : public StatefullTcpServer<TestState>
{
public:
	TestStatefullTcpServer(ILogService *logSrv, SignalService* sigSrv);
	virtual ~TestStatefullTcpServer();

	virtual TestState* createNewState();
	virtual void stateMutation(ClientInfo *client, string input);

	virtual bool validateCommand(string command);
	virtual void processCommand(ClientInfo *client, string command);

};

#endif // TestStatefullTcpServer_h__
