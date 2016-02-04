#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "TcpServer.h"
#include "TcpAcceptor.h"

using namespace std;

const char* TcpServer::DEFAULT_HOSTNAME = "localhost";

/*********************************
*
*		CONSTRUCTORS
*
**********************************/
TcpServer::TcpServer(ILogService *logSrv) : ITcpServer()
{
	this->logSrv = logSrv;

    this->port = DEFAULT_PORT;
    this->hostname = DEFAULT_HOSTNAME;

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
*		PUBLIC METHODS
*
**********************************/
void TcpServer::start()
{

    TcpStream* stream = NULL;
    TcpAcceptor* acceptor = new TcpAcceptor(port, hostname);

    if (acceptor->start() == 0)
    {
        this->logSrv->info("Tcp Server started and is waiting");

        while (1)
        {
            stream = acceptor->accept();

            if (stream  != NULL)
            {
                size_t len;
                char line[256];

                while ((len = stream->receive(line, sizeof(line))) > 0)
                {
                    line[len] = 0;

                    string mess(line);
                    this->logSrv->info("received - " + mess + "\n");

                    stream->send(line, len);
                }

                delete stream;

            } // if (stream  != NULL)
 
        } // while (1)

    } // if (acceptor->start() == 0)

    this->logSrv->error("Could not start the Server");
}

void TcpServer::action()
{
	this->identify();
	this->logSrv->outString("\n\n");

	this->start();
}