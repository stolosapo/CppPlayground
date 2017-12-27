#ifndef TestStatefullTcpServer_h__
#define TestStatefullTcpServer_h__

#include <string>

#include "StatefullTcpServer.h"
#include "TestState.h"
#include "../ClientInfo.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../../kernel/exception/ExceptionMapper.h"
#include "../../kernel/task/Locker.h"

using namespace std;

class TestStatefullTcpServer : public StatefullTcpServer<TestState>
{
public:
	TestStatefullTcpServer(ILogService *logSrv);
	virtual ~TestStatefullTcpServer();

	virtual TestState* createNewState();
	virtual void stateMutation(ClientInfo *client, string input);

	virtual bool validateCommand(string command);
	virtual void processCommand(ClientInfo *client, string command);

};

#endif // TestStatefullTcpServer_h__
