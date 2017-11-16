#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

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

void MultiThreadServer::acceptNewClient(pthread_t clientThread, ClientInfo* client)
{
    if (client->getStream() != NULL)
    {
        logSrv->info("Server start to accept new client");

        /* Start new thread for this client */
        // pthread_create(&clientThread, NULL, MultiThreadServer::taskHelper, client);

        Thread th;
        th += &MultiThreadServer::taskHelper;
        th.start(client);
    }
}

void* MultiThreadServer::task(void *context)
{
    ClientInfo* client = (ClientInfo *) context;

    TcpStream* stream = client->getStream();
    MultiThreadServer* server = (MultiThreadServer *) (client->getServer());

    ILogService* logger = server->logSrv;

    string input = "";
    string message = "";

    long threadNumber = pthread_self();
    string strThreadNumber = Convert<long>::NumberToString(threadNumber);
    string index = Convert<int>::NumberToString(client->getIndex());

    client->setThreadNumber(threadNumber);

    // Check new client for acceptance
    if (server->allowClient(client))
    {
    	logger->info("Server accepted new client");
	    logger->info("[ " + index + " ] - Thread No: " + strThreadNumber);

	    /* receive messages */
	    while (stream->receive(message) > 0)
	    {
	        input = message;
	        logger->info("received [" + index + " - " + strThreadNumber + "] - " + input);

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

	    logger->info("Client with threadNumber: " + strThreadNumber + " terminated");

	}
	else
    {
        logger->error("Server denied access to the client [ " + index + " ] with threadNumber: " + strThreadNumber);
    }

    delete client;
}

void* MultiThreadServer::taskHelper(void *context)
{
    return ((MultiThreadServer *)context)->task(context);
}


/*********************************
*
*		PUBLIC METHODS
*
**********************************/
void MultiThreadServer::start()
{
    string input = "";

    /* Thread pool */
    pthread_t clientThreadPool[DEFAULT_THREAD_POOL_SIZE];
    int noThread = 0;

    logSrv->info("Server is starting...");

    if (acceptor->start() == 0)
    {
        logSrv->info("Server is started");

        while (!TcpProtocol::shutdown(input))
        {
            /* Accept new client */
            TcpStream* stream = acceptor->accept();

            ClientInfo* newClient = new ClientInfo(this, stream, noThread);

            acceptNewClient(clientThreadPool[noThread], newClient);

            /* Increase thead counter */
            noThread++;
        }

        // for(int i = 0; i < DEFAULT_THREAD_POOL_SIZE; i++)
        // {
        //     pthread_join(clientThreadPool[i], NULL);
        // }

    }
    else
    {
        logSrv->error("Could not start the Server");
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

	acceptor = new TcpAcceptor(port, hostname.c_str());

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
