#include "IcecastClient.h"

#include "config/IcecastClientConfigLoader.h"


#include "../shared/convert.h"


IcecastClient::IcecastClient(ILogService *logSrv) : ITcpClient()
{
	this->logSrv = logSrv;
}

IcecastClient::~IcecastClient()
{
	delete protocol;
	delete config;
}

void IcecastClient::loadConfig()
{
	IcecastClientConfigLoader* loader = new IcecastClientConfigLoader("icecast.config");

	this->config = loader->load();

	this->protocol = new IcecastProtocol(this->config);

	delete loader;
}

void IcecastClient::action()
{
	loadConfig();

	string inMessage;

	string hostname = config->getHostname();
	string port = config->getPort();
	int intPort = Convert<int>::StringToNumber(port);

	logSrv->info("Client is connecting to server-> " + hostname + ":" + port);
    stream = connector->connect(intPort, hostname.c_str());

 	if (stream)
    {
		string outMessage = protocol->connectionRequest();

		stream->send(outMessage);

		logSrv->info("Sent: " + outMessage);

		stream->receive(inMessage);

		logSrv->info("Received: " + inMessage);


		delete stream;
    }
    else
    {
    	logSrv->error("Fail to connect");	
    }
}