#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "../../lib/converter/Convert.h"

#include "MultiThreadServer.h"
#include "../config/TcpServerConfigLoader.h"
#include "../lib/TcpAcceptor.h"
#include "../lib/TcpProtocol.h"
#include "../ClientInfo.h"

#include "../../lib/task/Thread.h"

using namespace std;

const char* MultiThreadServer::DEFAULT_HOSTNAME = "localhost";

/*********************************
*
*		CONSTRUCTORS
*
**********************************/
MultiThreadServer::MultiThreadServer(ILogService *logSrv) : ITcpServer()
{
	this->logSrv = logSrv;
}

MultiThreadServer::~MultiThreadServer()
{
	delete acceptor;

	if (this->pool != NULL) 
	{
		delete this->pool;
	}
}



/*********************************
*
*       PRIVATE METHODS
*
**********************************/
bool MultiThreadServer::allowClient(ClientInfo* client)
{
	bool accept = false;
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

	return accept;
}

void MultiThreadServer::acceptNewClient(ClientInfo* client)
{
	if (client->getStream() == NULL)
	{
		return;
	}

	logSrv->info("Server start to accept new client");

	/* Start new thread for this client */
	Thread* th = client->getThread();
	th->start(client);
}

void* MultiThreadServer::task(void *context)
{
	ClientInfo* client = (ClientInfo *) context;

	MultiThreadServer* server = (MultiThreadServer *) (client->getServer());
	
	ILogService* logger = server->logSrv;
	
	TcpStream* stream = client->getStream();
	
	Thread* th = client->getThread();
	th->setSelfId();


	string input = "";
	string message = "";


	string threadNumber = th->getStringId();
	string index = Convert<int>::NumberToString(client->getIndex());

	/* Check new client for acceptance */
	if (server->allowClient(client))
	{
		logger->info("Server accepted new client");
		logger->info("[ " + index + " ] - Thread No: " + threadNumber);

		/* receive messages */
		while (stream->receive(message) > 0)
		{
			input = message;
			logger->info("received [" + index + " - " + threadNumber + "] - " + input);

			if (server->validateCommand(input))
			{
				/* Process Message */
				server->processCommand(stream, input);

				stream->send(input);

			}
			else
			{
				/* send error message back */
				stream->send((string) TcpProtocol::INVALID_COMMAND);
			}
		}

		logger->info("Client with threadNumber: " + threadNumber + " terminated");

	}
	else
	{
		logger->error("Server denied access to the client [ " + index + " ] with threadNumber: " + threadNumber);
	}

	finalizeClient(client);
}

void* MultiThreadServer::taskHelper(void *context)
{
	return ((MultiThreadServer *)context)->task(context);
}

Thread* MultiThreadServer::getNextThread()
{
	Thread* th = pool->getNext();

	if (th == NULL)
	{
		return NULL;
	}

	th->attachDelegate(&MultiThreadServer::taskHelper);
	th->setMustDispose(true);

	return th;
}

void MultiThreadServer::finalizeClient(ClientInfo* client)
{
	MultiThreadServer* server = (MultiThreadServer *) (client->getServer());

	server->pool->putBack(client->getThread());

	delete client;
}

/*********************************
*
*		PUBLIC METHODS
*
**********************************/
void MultiThreadServer::start()
{
	string input = "";

	int clientCount = 0;

	
	logSrv->info("Server is starting...");

	if (acceptor->start() != 0)
	{
		logSrv->error("Could not start the Server");
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

		/* Take next thread */
		Thread* th = getNextThread();

		if (th == NULL)
		{
			delete stream;
			continue;
		}

		ClientInfo* newClient = new ClientInfo(this, stream, th, clientCount);

		acceptNewClient(newClient);

		/* Increase thead counter */
		clientCount++;
	}
}

void MultiThreadServer::action()
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

void MultiThreadServer::loadConfig()
{
	TcpServerConfigLoader* loader = new TcpServerConfigLoader("tcpServer.config");

	this->config = loader->load();

	delete loader;
}

void MultiThreadServer::initialize()
{
	if (this->config == NULL)
	{
		this->port = DEFAULT_PORT;
		this->hostname = string(DEFAULT_HOSTNAME);
	}
	else
	{
		int curPort = this->config->getPort();
		string curHostname = this->config->getHostname();

		if (curPort == 0 || curHostname == "")
		{
			curPort = DEFAULT_PORT;
			curHostname = string(DEFAULT_HOSTNAME);
		}

		this->port = curPort;
		this->hostname = curHostname;
	}

	/* Initialize acceptor */
	acceptor = new TcpAcceptor(port, hostname.c_str());

	/* Initialize thread pool */
	pool = new ThreadPool(config->getPoolsize());

	string strHostname = hostname;
	string strPort = Convert<int>::NumberToString(port);
	string strPoolsize = Convert<int>::NumberToString(this->config->getPoolsize());

	this->logSrv->info("Server Name: " + this->config->getName());
	this->logSrv->info("Server Description: " + this->config->getDescription());
	this->logSrv->info("Server Hostname: " + strHostname);
	this->logSrv->info("Server Port: " + strPort);
	this->logSrv->info("Server Poolsize: " + strPoolsize);
}

bool MultiThreadServer::handshake()
{
    	return true;
}

bool MultiThreadServer::validateCommand(string command)
{
	return TcpProtocol::validCommand(command);
}

void MultiThreadServer::processCommand(TcpStream *stream, string command)
{

}
