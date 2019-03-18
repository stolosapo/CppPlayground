#ifndef ITcpProtocol_h__
#define ITcpProtocol_h__

#include <string>

#include "../../exception/domain/DomainErrorCode.h"
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

	virtual string prompt();
	
	virtual bool isHelp(string command);
	virtual string help();

	static bool exit(string command);
	static bool shutdown(string command);
	static bool error(string command);
	static void error(ClientInfo *client);

protected:
	static const char* PROMPT;

	static const char* CLIENT_CONNECT;
	static const char* OK;
	static const char* DENIED;
	static const char* ERROR;

	static const char* HELP;
	static const char* EXIT;
	static const char* SHUTDOWN;

	bool getIsServer();

	void send(bool escape, ClientInfo *client, const char* command);
	void receive(bool escape, ClientInfo *client, const char* expected, const DomainErrorCode& errorCode);

	void serverSend(ClientInfo *client, const char* command);
	void serverReceive(ClientInfo *client, const char* expected, const DomainErrorCode& errorCode);

	void clientSend(ClientInfo *client, const char* command);
	void clientReceive(ClientInfo *client, const char* expected, const DomainErrorCode& errorCode);

};

#endif // ITcpProtocol_h__
