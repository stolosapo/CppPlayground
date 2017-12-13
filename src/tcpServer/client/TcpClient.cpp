#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "TcpClient.h"
#include "../config/TcpClientConfigLoader.h"
#include "../lib/TcpConnector.h"
#include "../lib/TcpProtocol.h"
#include "../../lib/converter/Convert.h"

#include "../ClientInfo.h"

#include "../../lib/exception/domain/DomainException.h"
#include "../exception/TcpClientErrorCode.h"

using namespace std;


/*********************************
*
*		CONSTRUCTORS
*
**********************************/
TcpClient::TcpClient(ILogService *logSrv) : ITcpClient(), logSrv(logSrv)
{
	this->in = new InOut;

	this->protocol = new ITcpProtocol(false);
}

TcpClient::~TcpClient()
{
	if (connector != NULL)
	{
		delete connector;
	}

	if (config != NULL)
	{
		delete config;
	}

	if (protocol != NULL)
	{
		delete protocol;
	}

	if (in != NULL)
	{
		delete in;
	}
}



/*********************************
*
*       PRIVATE METHODS
*
**********************************/
void TcpClient::finalizeClient(ClientInfo *client)
{
	if (client != NULL)
	{
		delete client;
	}
}



/*********************************
*
*		PUBLIC METHODS
*
**********************************/
void TcpClient::start()
{
	ClientInfo *client;

	try
	{
		logSrv->trace("Client is connecting to server...");
		stream = connector->connect(config->getServerPort(), config->getServerName().c_str());

		if (!stream)
		{
			throw DomainException(TcpClientErrorCode::TCC0001);
		}

		client = new ClientInfo(this, stream, 0);

		protocol->handshake(client);

		logSrv->info("Client is connected");

		bool cont = true;
		while (cont)
		{
			/* Proccess client */
			cont = cycle(client);

		}

	}
	catch (DomainException& e)
	{
		logSrv->error(e.what());
	}


	finalizeClient(client);
}

void TcpClient::action()
{
	this->loadConfig();

	this->initialize();

	this->start();
}


void TcpClient::loadConfig()
{
	TcpClientConfigLoader* loader = new TcpClientConfigLoader("tcpClient.config");

	this->config = loader->load();

	delete loader;
}


void TcpClient::initialize()
{
	connector = new TcpConnector();

	string strServerName = config->getServerName();
	int serverPort = config->getServerPort();
	string strServerPort = Convert<int>::NumberToString(serverPort);

	logSrv->info("Client Name: " + config->getName());
	logSrv->info("Client Description: " + config->getDescription());
	logSrv->info("Server Server Name: " + strServerName);
	logSrv->info("Server Port: " + strServerPort);
}

bool TcpClient::cycle(ClientInfo *client)
{
	TcpStream *stream = client->getStream();


	/* Prompt user for input */
	in->outString(ITcpProtocol::prompt());
	string userInput = in->inString();
	// string userInput = in->inLine();

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

void TcpClient::processCommand(ClientInfo *client, string command)
{

}
