#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "TcpClient.h"
#include "../TcpConnector.h"
#include "../TcpProtocol.h"

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


    // Initialize connection
    connector = new TcpConnector();
}

TcpClient::~TcpClient()
{
    delete connector;
}



/*********************************
*
*       PRIVATE METHODS
*
**********************************/
void TcpClient::test()
{
    // int len;
    // string message;
    // char line[256];

    // stream = connector->connect(port, hostname);

    // if (stream) 
    // {
    //     message = "Is there life on Mars?";
    //     stream->send(message.c_str(), message.size());
    //     // printf("sent - %s\n", message.c_str());
    //     this->logSrv->info("sent - " + message + "\n");


    //     len = stream->receive(line, sizeof(line));
    //     line[len] = 0;
    //     string mess(line);
    //     // printf("received - %s\n", line);
    //     this->logSrv->info("received - " + mess + "\n");

    //     delete stream;
    // }


    // stream = connector->connect(port, hostname);
    // if (stream) 
    // {
    //     message = "Why is there air?";
    //     stream->send(message.c_str(), message.size());
    //     // printf("sent - %s\n", message.c_str());
    //     this->logSrv->info("sent - " + message + "\n");


    //     len = stream->receive(line, sizeof(line));
    //     line[len] = 0;
    //     string mess(line);
    //     // printf("received - %s\n", line);
    //     this->logSrv->info("received - " + mess + "\n");

    //     delete stream;
    // }

}

bool TcpClient::askServerPermission()
{
    // ask for permission
    stream->send((string) TcpProtocol::CLIENT_CONNECT);

    // receive answer of permission
    string answer = "";
    stream->receive(answer);

    return answer == (string) TcpProtocol::OK;
}



/*********************************
*
*		PUBLIC METHODS
*
**********************************/
void TcpClient::start()
{
    string message;
    string input = "";

    
    logSrv->info("Client is connecting to server...");
    stream = connector->connect(port, hostname);

    if (stream) 
    {
        InOut *in = new InOut;

        // Ask server permission
        if (askServerPermission())
        {
            logSrv->info("Client is connected");

            while (!TcpProtocol::exit(input))
            {
                // Prompt for input
                logSrv->printl("");
                logSrv->print(TcpProtocol::PROMPT);
                input = in->inString();

                // Send messege to server
                stream->send(input);

                // Receive messege from server
                stream->receive(message);

                if (TcpProtocol::error(message))
                {
                    logSrv->error(message);
                }
            }
        }
        else
        {
            logSrv->error("Permission denied");
            logSrv->error("Client cannot connect to server");
        }

        delete stream;
    }

}

void TcpClient::action()
{
	this->identify();
	this->logSrv->outString("\n\n");

	this->start();
}