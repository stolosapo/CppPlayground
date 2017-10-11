#include "IcecastClient.h"

#include "config/IcecastClientConfigLoader.h"
#include "../audio/mp3/Mp3Parser.h"

#include "../lib/converter/Convert.h"


IcecastClient::IcecastClient(ILogService *logSrv) : ITcpClient()
{
	this->logSrv = logSrv;
}

IcecastClient::~IcecastClient()
{
	if (protocol != NULL)
	{
		// delete protocol;
	}

	if (config != NULL)
	{
		// delete config;
	}

	if (libShout != NULL)
	{
		// delete libShout;
	}
}

void IcecastClient::loadConfig()
{
	IcecastClientConfigLoader* loader = new IcecastClientConfigLoader("icecast.config");

	this->config = loader->load();

	this->protocol = new IcecastProtocol(this->config);

	delete loader;
}

void IcecastClient::streamAudio()
{
	// Mp3Parser mp3Parser;

	// mp3Parser.parse();

	libShout = new LibShout(logSrv, config);

	libShout->initializeShout();
}

void IcecastClient::action()
{
	loadConfig();

	streamAudio();

	return;



	const int BUFF_SIZE = 2048;
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

		logSrv->info("Sent:\n" + outMessage);

		char* inBuffer = new char[BUFF_SIZE];
		// stream->receive(inMessage);
		stream->receive(inBuffer, BUFF_SIZE);
		inMessage.assign(inBuffer, BUFF_SIZE);

		logSrv->info("Received:\n" + inMessage);

		/* Start streaming the audio */
		streamAudio();


		delete stream;
    }
    else
    {
    	logSrv->error("Fail to connect");
    }
}
