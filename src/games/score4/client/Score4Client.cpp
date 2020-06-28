#include "Score4Client.h"

#include "../../../kernel/console/Console.h"


Score4Client::Score4Client(ILogService *logSrv, SignalService *sigSrv) : TcpClient(logSrv, sigSrv)
{

}

Score4Client::~Score4Client()
{

}

bool Score4Client::cycle(ClientInfo *client)
{
	TcpStream *stream = client->getStream();


	/* Prompt user for input */
	Console::outString(protocol->prompt());

	string userInput = Console::inLine();

	if (ITcpProtocol::exit(userInput))
	{
		return false;
	}


	/* Send messege to server */
	stream->send(userInput);


	/* Receive messege from server */
	string serverInput = "";
	stream->receive(serverInput);

	if (ITcpProtocol::exit(serverInput))
	{
		return false;
	}


	if (!ITcpProtocol::error(serverInput))
	{
		processCommand(client, serverInput);
	}
	else
	{
		logSrv->error(serverInput);
	}


	return true;
}

void Score4Client::processCommand(ClientInfo *client, string command)
{
	Console::outStringln(command);
}
