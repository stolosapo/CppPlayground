#ifndef Score4Server_h__
#define Score4Server_h__

#include <string>

#include "../state/Score4State.h"

#include "../../../kernel/tcp/ClientInfo.h"
#include "../../../kernel/tcp/server/StatefullTcpServer.h"
#include "../../../kernel/interruption/SignalService.h"
#include "../../../kernel/time/ITimeService.h"

using namespace std;

class Score4Server : public StatefullTcpServer<Score4State>
{
public:
	Score4Server(ILogService *logSrv, SignalService *sigSrv, ITimeService *timeSrv);
	virtual ~Score4Server();

	virtual Score4State* createNewState();
	virtual void stateMutation(ClientInfo *client, string input);

	virtual bool validateCommand(string command);
	virtual void processCommand(ClientInfo *client, string command);

};

#endif // Score4Server_h__
