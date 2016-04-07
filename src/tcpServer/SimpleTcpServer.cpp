#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "SimpleTcpServer.h"

using namespace std;

/*********************************
*
*		CONSTRUCTORS
*
**********************************/
SimpleTcpServer::SimpleTcpServer(ILogService *logSrv) : ITcpServer()
{
	this->logSrv = logSrv;

    this->port = DEFAULT_PORT;

	this->setId(1);
	this->setName("Simple Tcp Server");
	this->setTitle("Simple Tcp Server");
	this->setDescription("The First Kube Simple Tcp Server");
}

SimpleTcpServer::~SimpleTcpServer()
{

}


/*********************************
*
*       GETTERS SETTERS
*
**********************************/
int SimpleTcpServer::getPort()
{
    return this->port;
}

bool SimpleTcpServer::isActive()
{
    return this->active;
}


void SimpleTcpServer::setPort(int port)
{
    this->port = port;
}


/*********************************
*
*		PRIVATE METHODS
*
**********************************/
void SimpleTcpServer::activate()
{
	this->active = true;
	this->logSrv->info("Server activated");
}

void SimpleTcpServer::passivate()
{
	this->active = false;
	this->logSrv->info("Server passivated");
}

int SimpleTcpServer::openSocket()
{

}

int SimpleTcpServer::doBind()
{

}

int SimpleTcpServer::listenSocket()
{

}

int SimpleTcpServer::acceptConnection()
{

}

int SimpleTcpServer::receive()
{

}

int SimpleTcpServer::send()
{

}

void SimpleTcpServer::test()
{
    
}


/*********************************
*
*		PUBLIC METHODS
*
**********************************/
void SimpleTcpServer::start()
{
	this->logSrv->info("Tcp Server started and is waiting");

	int sockfd;
    int newsockfd;
	socklen_t clilen;
 	char buffer[256];
	struct sockaddr_in serverAddress;
    struct sockaddr_in clientAddress;
    int n;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
       logSrv->fatal("ERROR opening socket");

    bzero((char *) &serverAddress, sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0)
             logSrv->fatal("ERROR on binding");

    listen(sockfd, 5);
    clilen = sizeof(clientAddress);
    newsockfd = accept(sockfd, (struct sockaddr *) &clientAddress, &clilen);

    if (newsockfd < 0)
         logSrv->fatal("ERROR on accept");

    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);

    if (n < 0) 
    	logSrv->fatal("ERROR reading from socket");
    
    printf("Here is the message: %s\n", buffer);

    n = write(newsockfd, "I got your message", 18);
    if (n < 0) 
    	logSrv->fatal("ERROR writing to socket");

    close(newsockfd);
    close(sockfd);

}

void SimpleTcpServer::action()
{
	this->identify();
	this->logSrv->outString("\n\n");

	this->activate();

	this->start();

	this->passivate();
}