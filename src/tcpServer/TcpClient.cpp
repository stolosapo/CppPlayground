#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "TcpClient.h"
#include "TcpConnector.h"

using namespace std;

const char* TcpClient::DEFAULT_HOSTNAME = "localhost";


/*********************************
*
*		CONSTRUCTORS
*
**********************************/
TcpClient::TcpClient(ILogService *logSrv) : ITcpClient()
{
	this->logSrv = logSrv;

    this->port = TcpClient::DEFAULT_PORT;
    this->hostname = TcpClient::DEFAULT_HOSTNAME;

	this->setId(2);
	this->setName("Tcp Client");
	this->setTitle("Tcp Client");
	this->setDescription("The First Kube Tcp Client");
}

TcpClient::~TcpClient()
{

}


/*********************************
*
*		PUBLIC METHODS
*
**********************************/
void TcpClient::start()
{
    int len;
    string message;
    char line[256];

    TcpConnector* connector = new TcpConnector();
    TcpStream* stream = connector->connect(port, hostname);

    if (stream) 
    {
        message = "Is there life on Mars?";
        stream->send(message.c_str(), message.size());
        // printf("sent - %s\n", message.c_str());
        this->logSrv->info("sent - " + message + "\n");


        len = stream->receive(line, sizeof(line));
        line[len] = 0;
        string mess(line);
        // printf("received - %s\n", line);
        this->logSrv->info("received - " + mess + "\n");

        delete stream;
    }


    stream = connector->connect(port, hostname);
    if (stream) 
    {
        message = "Why is there air?";
        stream->send(message.c_str(), message.size());
        // printf("sent - %s\n", message.c_str());
        this->logSrv->info("sent - " + message + "\n");


        len = stream->receive(line, sizeof(line));
        line[len] = 0;
        string mess(line);
        // printf("received - %s\n", line);
        this->logSrv->info("received - " + mess + "\n");

        delete stream;
    }

}

void TcpClient::action()
{
	this->identify();
	this->logSrv->outString("\n\n");

	this->start();
}