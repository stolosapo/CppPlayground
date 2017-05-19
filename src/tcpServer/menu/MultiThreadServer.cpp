#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "../../shared/convert.h"

#include "MultiThreadServer.h"
#include "../config/TcpServerConfigLoader.h"
#include "../TcpAcceptor.h"
#include "../TcpProtocol.h"
#include "../ClientInfo.h"

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

	this->setId(2);
	this->setName("Multi Thread Server");
	this->setTitle("Multi Thread Server");
	this->setDescription("The First Kube Multi Thread Server");
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

    return accept;
}

void MultiThreadServer::acceptNewClient(pthread_t clientThread, ClientInfo* client)
{
    if (client->getStream()  != NULL)
    {
        logSrv->printl("");
        logSrv->info("Server start to accept new client");

        // Check new client for acceptance
        if (allowClient(client))
        {
            logSrv->info("Server accepted new client");

            /* Start new thread for this client */
            pthread_create(&clientThread, NULL, MultiThreadServer::taskHelper, client);

        }
        else
        {
            logSrv->info("Server denied access to the client");

            delete client;
        }
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
	// initialize server
	initialize();

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
	this->identify();
	this->logSrv->outString("\n\n");

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

	cout << this->config->getServerPort() << " " << this->config->getServerHostname();

	delete loader;
}

void MultiThreadServer::initialize()
{
	// loadConfig();

	this->port = DEFAULT_PORT;
	this->hostname = DEFAULT_HOSTNAME;

	// if (this->config == NULL)
	// {
	// 	this->port = DEFAULT_PORT;
	// 	this->hostname = DEFAULT_HOSTNAME;
	// }
	// else
	// {
	// 	this->port = this->config->getServerPort();
	// 	this->hostname = this->config->getServerHostname().c_str();
	// }

	acceptor = new TcpAcceptor(port, hostname);
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
