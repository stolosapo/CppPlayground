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

bool TcpServer::handshake()
{
    return true;
}

void TcpServer::processCommand(TcpStream *stream, string command)
{

}


/*********************************
*
*		PUBLIC METHODS
*
**********************************/
void TcpServer::start()
{
    string input = "";
    string message = "";

    logSrv->info("Server is starting...");

    if (acceptor->start() == 0)
    {
        logSrv->info("Server is started");

        while (!TcpProtocol::shutdown(input))
        {
            // Accept new client
            stream = acceptor->accept();

            if (stream  != NULL)
            {
                logSrv->printl("");
                logSrv->info("Server start to accept new client");

                // Check new client for acceptance
                if (acceptClient())
                {
                    logSrv->info("Server accepted new client");

                    // receive messages
                    while (stream->receive(message) > 0)
                    {
                        input = message;
                        logSrv->printl("received - " + input);

                        if (TcpProtocol::validCommand(input))
                        {

                            /* Process Message */
                            processCommand(stream, input);


                            stream->send(input);
                        }
                        else
                        {
                            // send error message back
                            stream->send((string) TcpProtocol::INVALID_COMMAND);
                        }
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