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
TcpServer::TcpServer(ILogService *logSrv) : MenuItem()
{
	this->logSrv = logSrv;

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
*		PRIVATE METHODS
*
**********************************/
void TcpServer::activate()
{
	this->isActive = true;
	this->logSrv->info("Server activated");
}

void TcpServer::passivate()
{
	this->isActive = false;
	this->logSrv->info("Server passivated");
}


/*********************************
*
*		PUBLIC METHODS
*
**********************************/
void TcpServer::start()
{
	this->logSrv->info("Tcp Server started and is waiting");

	int sockfd, newsockfd, portno = 51717;
	socklen_t clilen;
 	char buffer[256];
	struct sockaddr_in serv_addr, cli_addr;
    int n;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
       logSrv->fatal("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
             logSrv->fatal("ERROR on binding");

    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

    if (newsockfd < 0)
         logSrv->fatal("ERROR on accept");

    bzero(buffer,256);
    n = read(newsockfd,buffer,255);

    if (n < 0) 
    	logSrv->fatal("ERROR reading from socket");
    
    printf("Here is the message: %s\n", buffer);

    n = write(newsockfd,"I got your message", 18);
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