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
TcpServer::TcpServer(ILogService *logSrv) : ITcpServer(), logSrv(logSrv)
{
	this->protocol = new ITcpProtocol(true);
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

	if (this->protocol != NULL)
	{
		delete this->protocol;
	}
}



/*********************************
*
*       PRIVATE METHODS
*
**********************************/
void* TcpServer::task(void *context)
{
	ClientInfo* client = (ClientInfo *) context;
	client->getThread()->setSelfId();

	TcpServer* server = (TcpServer *) (client->getServer());
	ILogService* logger = server->logSrv;
	TcpStream* stream = client->getStream();


	string input = "";

	string identity = client->getIdentity();

	try
	{
		/* Check new client for acceptance */
		server->protocol->handshake(client);

		logger->trace("Server accepted new client: [" + identity + "]");


		/* receive messages */
		while (stream->receive(input) > 0)
		{

			/* Proccess input */
			server->cycle(client, input);

		}

		logger->trace("Client [" + identity + "] terminated");
	}
	catch (DomainException& e)
	{
		logger->error(e.what());
	}


	finalizeClient(client);
}

void* TcpServer::internalClientTask(void *context)
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

	th->attachDelegate(&TcpServer::internalClientTask);
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

	while (!ITcpProtocol::shutdown(input))
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

void TcpServer::cycle(ClientInfo *client, string input)
{
	TcpStream *stream = client->getStream();


	logSrv->trace("received [" + client->getIdentity() + "] - " + input);

	if (validateCommand(input))
	{
		/* Process Message */
		processCommand(client, input);

		stream->send(input);
	}
	else
	{
		/* send error message back */
		ITcpProtocol::error(client);
	}
}

bool TcpServer::validateCommand(string command)
{
	return TcpProtocol::validCommand(command);
}

void TcpServer::processCommand(ClientInfo *client, string command)
{

}
