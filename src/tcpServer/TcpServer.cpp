#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "TcpServer.h"
#include "TcpAcceptor.h"
#include "TcpProtocol.h"

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

    // initialize server
    stream = NULL;
    acceptor = new TcpAcceptor(port, hostname);
}

TcpServer::~TcpServer()
{
    delete acceptor;
}



/*********************************
*
*       PRIVATE METHODS
*
**********************************/
bool TcpServer::acceptClient()
{
    bool accept = false;

    size_t len;
    char line[256];
    string input = "";

    len = stream->receive(line, sizeof(line));

    if (len > 0)
    {
        line[len] = 0;
        input = (string) line;

        if (input == (string) TcpProtocol::CLIENT_CONNECT)
        {
            string ok = (string) TcpProtocol::OK;

            stream->send(ok.c_str(), ok.size());

            accept = true;
        }
    }

    return accept;
}



/*********************************
*
*		PUBLIC METHODS
*
**********************************/
void TcpServer::start()
{
    string input = "";

    logSrv->info("Server is starting...");

    if (acceptor->start() == 0)
    {
        logSrv->info("Server is started");

        while (!TcpProtocol::shutdown(input))
        {
            stream = acceptor->accept();

            if (stream  != NULL)
            {
                logSrv->printl("");
                logSrv->info("Server start to accept new client");

                if (acceptClient())
                {
                    logSrv->info("Server accepted new client");

                    size_t len;
                    char line[256];

                    while ((len = stream->receive(line, sizeof(line))) > 0)
                    {
                        line[len] = 0;

                        input = (string) line;
                        logSrv->printl("received - " + input);

                        stream->send(line, len);
                    }
                }
                else
                {
                    logSrv->info("Server denied access to the client");
                }

                delete stream;

                logSrv->info("Server accepted client terminated");

            } // if (stream  != NULL)
 
        } // while (!TcpProtocol::shutdown(input))

    } // if (acceptor->start() == 0)
    else
    {
        logSrv->error("Could not start the Server");
    }

}

void TcpServer::action()
{
	this->identify();
	this->logSrv->outString("\n\n");

	this->start();
}