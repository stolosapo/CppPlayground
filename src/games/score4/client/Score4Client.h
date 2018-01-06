#ifndef Score4Client_h__
#define Score4Client_h__

#include <string>

#include "../../../kernel/tcp/ClientInfo.h"
#include "../../../kernel/tcp/client/TcpClient.h"

using namespace std;

class Score4Client : public TcpClient
{
public:
	Score4Client(ILogService *logSrv);
	virtual ~Score4Client();

protected:
	virtual bool cycle(ClientInfo *client);
	virtual void processCommand(ClientInfo *client, string command);

};

#endif // Score4Client_h__
