#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "../../lib/converter/Convert.h"

#include "TcpServer.h"
#include "../config/TcpServerConfigLoader.h"
#include "../lib/TcpAcceptor.h"
#include "../lib/TcpProtocol.h"
#include "../ClientInfo.h"

#include "../../lib/task/Thread.h"

#include "../../lib/exception/domain/DomainException.h"
#include "../exception/TcpServerErrorCode.h"

using namespace std;


/*********************************
*
*		CONSTRUCTORS
*
**********************************/
TcpServer::TcpServer(ILogService *logSrv) : ITcpServer()
{
	this->logSrv = logSrv;
}

TcpServer::~TcpServer()
{
	delete acceptor;

	if (this->pool != NULL)
	{
		delete this->pool;
	}

	if (this->config != NULL)
	{
		delete this->config;
	}
}



/*********************************
*
*       PRIVATE METHODS
*
**********************************/
bool TcpServer::allowClient(ClientInfo* client)
{
	bool accept = false;

	TcpServer* server = (TcpServer *) (client->getServer());
	ILogService* logger = server->logSrv;
	TcpStream* stream = client->getStream();

	string input = "";
	stream->receive(input);

	if (TcpProtocol::validAckCommand(input))
	{
		if (input == (string) TcpProtocol::CLIENT_CONNECT)
		{
			stream->send((string) TcpProtocol::OK);

			accept = handshake();
		}
	}
	else
	{
		logSrv->error("Client sent: " + input);
	}

	if (!accept)
	{
		string identity = client->getIdentity();
		logger->error("Server denied access to the client [ " + identity + " ]");

		throw DomainException(TcpServerErrorCode::TCS0002);
	}

	return accept;
}

void* TcpServer::task(void *context)
{
	ClientInfo* client = (ClientInfo *) context;
	client->getThread()->setSelfId();

	TcpServer* server = (TcpServer *) (client->getServer());
	ILogService* logger = server->logSrv;
	TcpStream* stream = client->getStream();


	string input = "";
	string message = "";

	string identity = client->getIdentity();

	try
	{
		/* Check new client for acceptance */
		server->allowClient(client);

		logger->trace("Server accepted new client: [" + identity + "]");


		/* receive messages */
		while (stream->receive(message) > 0)
		{
			input = message;
			logger->trace("received [" + identity + "] - " + input);

			if (server->validateCommand(input))
			{
				/* Process Message */
				server->processCommand(client, input);

				stream->send(input);

			}
			else
			{
				/* send error message back */
				stream->send((string) TcpProtocol::INVALID_COMMAND);
			}
		}

		logger->trace("Client [" + identity + "] terminated");
	}
	catch (DomainException& e)
	{
		logger->error(e.what());
	}


	finalizeClient(client);
}

void* TcpServer::taskHelper(void *context)
{
	return ((TcpServer *)context)->task(context);
}

Thread* TcpServer::getNextThread()
{
	Thread* th = pool->getNext();

	if (th == NULL)
	{
		return NULL;
	}

	th->attachDelegate(&TcpServer::taskHelper);
	th->setMustDispose(true);

	return th;
}

void TcpServer::finalizeClient(ClientInfo* client)
{
	TcpServer* server = (TcpServer *) (client->getServer());

	server->pool->putBack(client->getThread());

	delete client;
}

/*********************************
*
*		PUBLIC METHODS
*
**********************************/
void TcpServer::start()
{
	string input = "";

	int clientCount = 0;


	logSrv->trace("Server is starting...");

	if (acceptor->start() != 0)
	{
		throw DomainException(TcpServerErrorCode::TCS0001);
	}


	logSrv->info("Server is started");

	while (!TcpProtocol::shutdown(input))
	{
		if (!pool->hasNext())
		{
			continue;
		}


		/* Accept new client */
		TcpStream* stream = acceptor->accept();

		if (stream == NULL)
		{
			continue;
		}


		/* Take next thread */
		Thread* th = getNextThread();

		if (th == NULL)
		{
			delete stream;
			continue;
		}


		/* Create new client and start in new thread */
		ClientInfo* client = new ClientInfo(this, stream, th, clientCount);

		th->start(client);


		/* Increase thead counter */
		clientCount++;
	}
}

void TcpServer::action()
{
	this->loadConfig();

	this->initialize();

	this->start();
}


/*********************************
*
*		PROTECTED METHODS
*
**********************************/

void TcpServer::loadConfig()
{
	TcpServerConfigLoader* loader = new TcpServerConfigLoader("tcpServer.config");

	this->config = loader->load();

	delete loader;
}

void TcpServer::initialize()
{
	string hostname = config->getHostname();
	int port = config->getPort();
	int poolSize = config->getPoolsize();

	/* Initialize acceptor */
	acceptor = new TcpAcceptor(port, hostname.c_str());

	/* Initialize thread pool */
	pool = new ThreadPool(poolSize);

	logSrv->info("Server Name: " + config->getName());
	logSrv->info("Server Description: " + config->getDescription());
	logSrv->info("Server Hostname: " + hostname);
	logSrv->info("Server Port: " + Convert<int>::NumberToString(port));
	logSrv->info("Server Poolsize: " + Convert<int>::NumberToString(poolSize));
}

bool TcpServer::handshake()
{
    	return true;
}

bool TcpServer::validateCommand(string command)
{
	return TcpProtocol::validCommand(command);
}

void TcpServer::processCommand(ClientInfo *client, string command)
{

}
