#include "TestStatefullTcpServer.h"

TestStatefullTcpServer::TestStatefullTcpServer(ILogService *logSrv) : StatefullTcpServer(logSrv)
{

}

TestStatefullTcpServer::~TestStatefullTcpServer()
{

}

TestState* TestStatefullTcpServer::createNewState()
{
	logSrv->trace("Create new state");

	return new TestState;
}

void TestStatefullTcpServer::stateMutation(ClientInfo *client, string input)
{
	if (input == "clear")
	{
		state = createNewState();
		logSrv->trace("State cleared");
		
		return;
	}

	logSrv->trace("Current state name: " + state->getName());

	state->setName(input);

	logSrv->trace("Changed state name to: " + state->getName());	
}

bool TestStatefullTcpServer::validateCommand(string command)
{
	return true;
}

void TestStatefullTcpServer::processCommand(ClientInfo *client, string command)
{
	TcpStream *stream = client->getStream();

	if (command == "list")
	{
		stream->send(state->getName());
	}
	else
	{
		safeStateMutation(client, command);
		stream->send("Changed");
	}
}