#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "../../converter/Convert.h"

#include "TcpServer.h"
#include "../lib/TcpAcceptor.h"
#include "../lib/TcpProtocol.h"
#include "../ClientInfo.h"

#include "../../task/Thread.h"

#include "../../configuration/ConfigLoader.h"
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

    this->acceptor = NULL;
    this->pool = NULL;
    this->config = NULL;
    this->protocol = NULL;
}

TcpServer::~TcpServer()
{
    if (this->acceptor != NULL)
    {
        delete this->acceptor;
    }

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

    for (map<int, ClientInfo*>::iterator it = activeClients.begin();
        it != activeClients.end();
        ++it)
	{
        if (it->second != NULL)
        {
            delete it->second;
            logSrv->info("Finalized client: " + Convert<int>::NumberToString(it->first));
        }
	}

	activeClients.clear();

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

    return NULL;
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

    map<int, ClientInfo*>::iterator it = server->activeClients.find(client->getIndex());
    if (it != server->activeClients.end())
    {
        server->activeClients.erase(it);
    }

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

int TcpServer::numberOfActiveConnections()
{
	return pool->numberOfActiveThreads();
}

void TcpServer::start()
{
	int clientCount = 0;

	logSrv->trace("Server is starting...");

	if (acceptor->start() != 0)
	{
		throw DomainException(TcpServerErrorCode::TCS0001);
	}

	logSrv->info("Server is started");

	while (!sigSrv->gotSigInt())
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
        string name = "TcpClient" + Convert<int>::NumberToString(clientCount);
		// th->setName(name.c_str());


        /* Add this client to active clients */
        activeClients[client->getIndex()] = client;


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

string TcpServer::configFilename()
{
	return "tcp/tcpServer.config";
}

void TcpServer::loadConfig()
{
	string file = configFilename();

    ConfigLoader<TcpServerConfig> loader(file);
    this->config = loader.load();

	logSrv->info("Configuration Loaded. '" + file + "'");
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
