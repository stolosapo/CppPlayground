#include "Score4Server.h"


Score4Server::Score4Server(ILogService *logSrv) : StatefullTcpServer(logSrv)
{

}

Score4Server::~Score4Server()
{

}

Score4State* Score4Server::createNewState()
{
	return new Score4State;
}

void Score4Server::stateMutation(ClientInfo *client, string input)
{
	ILogService* logger = ((Score4Server*) client->getServer())->logger();

	logger->trace("Mutate state");

	logger = NULL;
}

bool Score4Server::validateCommand(string command)
{
	return true;
}

void Score4Server::processCommand(ClientInfo *client, string command)
{
	TcpStream *stream = client->getStream();

	safeStateMutation(client, command);
	stream->send("OK");
}