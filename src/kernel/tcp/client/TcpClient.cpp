#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "TcpClient.h"
#include "../config/TcpClientConfigLoader.h"
#include "../lib/TcpConnector.h"
#include "../lib/TcpProtocol.h"
#include "../../converter/Convert.h"

#include "../ClientInfo.h"

#include "../../exception/domain/DomainException.h"
#include "../../exception/ExceptionMapper.h"
#include "../exception/TcpClientErrorCode.h"

using namespace std;


/*********************************
*
*		CONSTRUCTORS
*
**********************************/
TcpClient::TcpClient(ILogService *logSrv, SignalService *sigSrv) : ITcpClient(), logSrv(logSrv), sigSrv(sigSrv)
{
	this->in = new InOut;
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

	client = NULL;

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

			/* Check for interruption */
			if (sigSrv->gotSigInt())
			{

				logSrv->debug("Stopping client.. ");

				break;
			}

			/* Proccess client */
			cont = cycle(client);
		}

	}
	catch (DomainException& e)
	{
		logSrv->error(handle(e));
	}


	finalizeClient(client);
}

void TcpClient::action()
{
	this->protocol = createProtocol();

	this->loadConfig();

	this->initialize();

	this->start();
}

ITcpProtocol* TcpClient::createProtocol()
{
	return new ITcpProtocol(false);
}

const char* TcpClient::configFilename()
{
	return "tcpClient.config";
}

void TcpClient::loadConfig()
{
	TcpClientConfigLoader* loader = new TcpClientConfigLoader(configFilename());

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
	in->outString(protocol->prompt());
	string userInput = in->inLine();

	if (userInput == "")
	{
		return true;
	}

	if (protocol->isHelp(userInput))
	{
		in->outString(protocol->help());
		return true;
	}

	if (ITcpProtocol::exit(userInput))
	{
		return false;
	}


	/* Send messege to server */
	stream->send(userInput);


	/* Receive messege from server */
	string serverInput = "";
	ssize_t size = stream->receiveAll(serverInput);


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
	in->outString(command + "\n");
}
