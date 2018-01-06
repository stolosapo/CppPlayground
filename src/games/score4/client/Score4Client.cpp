#include "Score4Client.h"

Score4Client::Score4Client(ILogService *logSrv) : TcpClient(logSrv)
{

}

Score4Client::~Score4Client()
{

}

bool Score4Client::cycle(ClientInfo *client)
{
	TcpStream *stream = client->getStream();


	/* Prompt user for input */
	in->outString(ITcpProtocol::prompt());
	
	string userInput = in->inLine();

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
	in->outString(command + "\n");
}