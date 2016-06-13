#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include "SimpleTcpClient.h"

using namespace std;

/*********************************
*
*		CONSTRUCTORS
*
**********************************/
SimpleTcpClient::SimpleTcpClient(ILogService *logSrv) : ITcpClient()
{
	this->logSrv = logSrv;

	this->setId(2);
	this->setName("Simple Tcp Client");
	this->setTitle("Simple Tcp Client");
	this->setDescription("The First Kube Simple Tcp Client");
}

SimpleTcpClient::~SimpleTcpClient()
{

}


/*********************************
*
*		PRIVATE METHODS
*
**********************************/
void SimpleTcpClient::test()
{
	this->logSrv->info("This is a Tcp test");

	this->testConnect();
}

void SimpleTcpClient::testConnect()
{
	char* hostname = "localhost";
	int sockfd, portno = 51717, n;

    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        logSrv->fatal("ERROR opening socket");

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        logSrv->fatal("ERROR connecting");

    printf("Please enter the message: ");
    bzero(buffer, 256);
    fgets(buffer, 255, stdin);
    n = write(sockfd,buffer, strlen(buffer));

    if (n < 0)
        logSrv->fatal("ERROR writing to socket");

    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0)
        logSrv->fatal("ERROR reading from socket");

    printf("%s\n", buffer);
    close(sockfd);
}


/*********************************
*
*		PUBLIC METHODS
*
**********************************/
void SimpleTcpClient::action()
{
	this->identify();
	this->logSrv->outString("\n\n");

	this->test();
}