#ifndef ITcpProtocol_h__
#define ITcpProtocol_h__

#include <string>
#include "../ClientInfo.h"

using namespace std;

class ITcpProtocol
{
private:
	bool isServer;

public:
	ITcpProtocol(bool isServer);
	virtual ~ITcpProtocol();

	void handshake(ClientInfo *client);
	void authenticate(ClientInfo *client);

protected:
	static const char* PROMPT;

	static const char* CLIENT_CONNECT;
	static const char* OK;
	static const char* DENIED;
	static const char* INVALID_COMMAND;

	static const char* HELP;
	static const char* EXIT;
	static const char* SHUTDOWN;

	bool getIsServer();

	void send(bool escape, ClientInfo *client, string command);
	void receive(bool escape, ClientInfo *client, string expected);

	void serverSend(ClientInfo *client, string command);
	void serverReceive(ClientInfo *client, string expected);

	void clientSend(ClientInfo *client, string command);
	void clientReceive(ClientInfo *client, string expected);

};

#endif // ITcpProtocol_h__