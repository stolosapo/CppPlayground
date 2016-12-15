#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "MultiThreadServer.h"
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

    this->port = DEFAULT_PORT;
    this->hostname = DEFAULT_HOSTNAME;

	this->setId(2);
	this->setName("Multi Thread Server");
	this->setTitle("Multi Thread Server");
	this->setDescription("The First Kube Multi Thread Server");

    // initialize server
    acceptor = new TcpAcceptor(port, hostname);
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

bool MultiThreadServer::handshake()
{
    return true;
}

void MultiThreadServer::processCommand(TcpStream *stream, string command)
{

}

void* MultiThreadServer::task(void *context)
{
    ClientInfo* client = (ClientInfo *) context;

    TcpStream* stream = client->getStream();
    MultiThreadServer* server = (MultiThreadServer *) (client->getServer());

    string input = "";
    string message = "";

    cout << "Thread No: " << pthread_self() << endl;

    /* receive messages */
    while (stream->receive(message) > 0)
    {
        input = message;
        server->logSrv->printl("received - " + input);

        if (TcpProtocol::validCommand(input))
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
    
    server->logSrv->info("Server accepted client terminated");

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

            ClientInfo* newClient = new ClientInfo(this, stream);

            acceptNewClient(clientThreadPool[noThread], newClient);

            /* Increase thead counter */
            noThread++;
        }

        // for(int i = 0; i < DEFAULT_THREAD_POOL_SIZE; i++)
        // {
        //     pthread_join(threadA[i], NULL);
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