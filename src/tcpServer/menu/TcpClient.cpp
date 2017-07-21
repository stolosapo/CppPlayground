#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "TcpClient.h"
#include "../config/TcpClientConfigLoader.h"
#include "../TcpConnector.h"
#include "../TcpProtocol.h"
#include "../../lib/converter/Convert.h"

using namespace std;

const char* TcpClient::DEFAULT_SERVERNAME = "localhost";


/*********************************
*
*		CONSTRUCTORS
*
**********************************/
TcpClient::TcpClient(ILogService *logSrv) : ITcpClient()
{
	this->logSrv = logSrv;

	this->port = TcpClient::DEFAULT_PORT;
	this->serverName = string(TcpClient::DEFAULT_SERVERNAME);

	this->setId(3);
	this->setName("Tcp Client");
	this->setTitle("Tcp Client");
	this->setDescription("The First Kube Tcp Client");
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

    // stream = connector->connect(port, serverName);

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


    // stream = connector->connect(port, serverName);
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
    stream = connector->connect(port, serverName.c_str());

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

	this->loadConfig();

	this->initialize();

	this->start();
}


void TcpClient::loadConfig()
{
	TcpClientConfigLoader* loader = new TcpClientConfigLoader("tcpClient.config");

	this->config = loader->load();

	delete loader;
}


void TcpClient::initialize()
{
	if (this->config == NULL)
	{
		this->port = DEFAULT_PORT;
		this->serverName = string(DEFAULT_SERVERNAME);
	}
	else
	{
		int curPort = this->config->getServerPort();
		string curServerName = this->config->getServerName();

		if (curPort == 0 || curServerName == "")
		{
			curPort = DEFAULT_PORT;
			curServerName = string(DEFAULT_SERVERNAME);
		}

		this->port = curPort;
		this->serverName = curServerName;
	}

	connector = new TcpConnector();

	string strServerName = serverName;
	string strServerPort = Convert<int>::NumberToString(port);

	this->logSrv->info("Client Name: " + this->config->getName());
	this->logSrv->info("Client Description: " + this->config->getDescription());
	this->logSrv->info("Server Server Name: " + strServerName);
	this->logSrv->info("Server Port: " + strServerPort);
}
