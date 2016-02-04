#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "TcpServer.h"

using namespace std;

/*********************************
*
*		CONSTRUCTORS
*
**********************************/
TcpServer::TcpServer(ILogService *logSrv) : ITcpServer()
{
	this->logSrv = logSrv;

    this->port = DEFAULT_PORT;

	this->setId(1);
	this->setName("Tcp Server");
	this->setTitle("Tcp Server");
	this->setDescription("The First Kube Tcp Server");
}

TcpServer::~TcpServer()
{

}


/*********************************
*
*       GETTERS SETTERS
*
**********************************/
int TcpServer::getPort()
{
    return this->port;
}

bool TcpServer::isActive()
{
    return this->active;
}


void TcpServer::setPort(int port)
{
    this->port = port;
}


/*********************************
*
*		PRIVATE METHODS
*
**********************************/
void TcpServer::activate()
{
	this->active = true;
	this->logSrv->info("Server activated");
}

void TcpServer::passivate()
{
	this->active = false;
	this->logSrv->info("Server passivated");
}

int TcpServer::openSocket()
{

}

int TcpServer::doBind()
{

}

int TcpServer::listenSocket()
{

}

int TcpServer::acceptConnection()
{

}

int TcpServer::receive()
{

}

int TcpServer::send()
{

}

void TcpServer::test()
{
    
}


/*********************************
*
*		PUBLIC METHODS
*
**********************************/
void TcpServer::start()
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

void TcpServer::action()
{
	this->identify();
	this->logSrv->outString("\n\n");

	this->activate();

	this->start();

	this->passivate();
}