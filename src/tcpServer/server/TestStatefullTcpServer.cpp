#include "TestStatefullTcpServer.h"

#include "../../kernel/converter/Convert.h"

TestStatefullTcpServer::TestStatefullTcpServer(ILogService *logSrv) : StatefullTcpServer(logSrv)
{

}

TestStatefullTcpServer::~TestStatefullTcpServer()
{

}

TestState* TestStatefullTcpServer::createNewState()
{
	return new TestState;
}

void TestStatefullTcpServer::stateMutation(ClientInfo *client, string input)
{
	ILogService* logger = ((TestStatefullTcpServer*) client->getServer())->logger();

	string identity = client->getIdentity();
	string id = Convert<int>::NumberToString(client->getIndex());

	if (input == "clear")
	{
		state = createNewState();
		logger->trace(identity + " State cleared");
		
		return;
	}

	// input = state->getName() + "->" + input + id;
	input = input + id;

	logger->trace(identity + " Current state name: " + state->getName());

	state->setName(input);

	logger->trace(identity + " Changed state name to: " + state->getName());

	logger = NULL;
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