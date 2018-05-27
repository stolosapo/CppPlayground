#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "../../converter/Convert.h"

#include "TcpServer.h"
#include "../config/TcpServerConfigLoader.h"
#include "../lib/TcpAcceptor.h"
#include "../lib/TcpProtocol.h"
#include "../ClientInfo.h"

#include "../../task/Thread.h"

#include "../../exception/domain/DomainException.h"
#include "../../exception/ExceptionMapper.h"
#include "../exception/TcpServerErrorCode.h"

using namespace std;


/*********************************
*
*		CONSTRUCTORS
*
**********************************/
TcpServer::TcpServer(ILogService *logSrv, SignalService *sigSrv, ITimeService* timeSrv) 
	: ITcpServer(), logSrv(logSrv), sigSrv(sigSrv), timeSrv(timeSrv)
{
	startTime = timeSrv->rawNow();
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

	logSrv->trace("Server finalized!");
}



/*********************************
*
*       PRIVATE METHODS
*
**********************************/
void* TcpServer::task(void *context)
{
	ClientInfo* client = (ClientInfo *) context;
	// client->getThread()->setSelfId();

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
		logger->error(handle(e));
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
ILogService* TcpServer::logger()
{
	return this->logSrv;
}

ITcpProtocol* TcpServer::getProtocol()
{
	return this->protocol;
}

double TcpServer::uptime()
{
	time_t now = timeSrv->rawNow();

	return difftime(now, startTime);
}

void TcpServer::start()
{
	string input = "";
	int clientCount = 0;

	vector<ClientInfo*> clients;


	logSrv->trace("Server is starting...");

	if (acceptor->start() != 0)
	{
		throw DomainException(TcpServerErrorCode::TCS0001);
	}


	logSrv->info("Server is started");

	while (!ITcpProtocol::shutdown(input) && !sigSrv->gotSigInt())
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

		clients.push_back(client);


		/* Increase thead counter */
		clientCount++;
	}

	logSrv->debug("Stopping server..");
}

void TcpServer::action()
{
	this->protocol = createProtocol();

	this->loadConfig();

	this->initialize();

	this->start();
}


/*********************************
*
*		PROTECTED METHODS
*
**********************************/

ITcpProtocol* TcpServer::createProtocol()
{
	return new ITcpProtocol(true);
}

const char* TcpServer::configFilename()
{
	return "tcpServer.config";
}

void TcpServer::loadConfig()
{
	TcpServerConfigLoader* loader = new TcpServerConfigLoader(configFilename());

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
	ILogService* logger = ((TcpServer*) client->getServer())->logger();

	string trace = "received [" + client->getIdentity() + "] - " + input;

	logger->trace(trace);

	if (validateCommand(input))
	{
		/* Process Message */
		processCommand(client, input);
	}
	else
	{
		/* Process Error Message */
		processErrorCommand(client, input);
	}

	logger = NULL;
}

bool TcpServer::validateCommand(string command)
{
	return TcpProtocol::validCommand(command);
}

void TcpServer::processCommand(ClientInfo *client, string command)
{
	TcpStream *stream = client->getStream();

	stream->send(command);
}

void TcpServer::processErrorCommand(ClientInfo *client, string command)
{
	/* send error message back */
	ITcpProtocol::error(client);
}
