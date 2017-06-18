#include "IcecastClient.h"

#include "config/IcecastClientConfigLoader.h"

#include "../shared/convert.h"

/*
	https://stackoverflow.com/questions/9239022/broadcast-to-icecast-shoutcast-with-objective-c-c-or-c
	https://gist.github.com/ePirat/adc3b8ba00d85b7e3870


	SOURCE /thefirstkube.mp3 HTTP/1.0
	Authorization: Basic c291cmNlOmowdnlz
	User-Agent: ices/0.4 libshout/2.2.2
	Content-Type: audio/mpeg
	ice-name: The First Kube
	ice-public: 1
	ice-url: http://www.thefirstkube.net
	ice-genre: Experimental Industrial Noise and more...
	ice-audio-info: bitrate=128
	ice-description: An Experimenatl Industrial Noise Radio
*/

IcecastClient::IcecastClient(ILogService *logSrv) : ITcpClient()
{
	this->newLine = "\r\n";

	this->logSrv = logSrv;
}

IcecastClient::~IcecastClient()
{
	delete config;
}

void IcecastClient::loadConfig()
{
	IcecastClientConfigLoader* loader = new IcecastClientConfigLoader("icecast.config");

	this->config = loader->load();

	delete loader;
}

void IcecastClient::action()
{
	loadConfig();

	string inMessage = "";
	string outMessage;

	string hostname = config->getHostname();
	string port = config->getPort();
	int intPort = Convert<int>::StringToNumber(port);
	string password = config->getPassword();
	string mountpoint = config->getMountpoint();
	string name = config->getName();
	string _public = config->getPublic();
	string url = config->getUrl();
	string genre = config->getGenre();
	string bitrate = config->getBitrate();
	string description = config->getDescription();

	logSrv->info("Client is connecting to server-> " + hostname + ":" + port);
    stream = connector->connect(intPort, hostname.c_str());

 	if (stream)
    {
		outMessage = "PUT " + mountpoint + " HTTP/1.1" + newLine +
			"Authorization: Basic c291cmNlOmowdnlz" + newLine +
			"User-Agent: ices/0.4 libshout/2.2.2" + newLine +
			"Content-Type: audio/mpeg" + newLine +
			"ice-name: " + name + newLine +
			"ice-public: " + _public + newLine +
			"ice-url: " + url + newLine +
			"ice-genre: " + genre + newLine +
			"ice-audio-info: bitrate=" + bitrate + newLine +
			"ice-description: " + description + newLine + newLine;

		stream->send(outMessage);

		logSrv->info("Sent: " + outMessage);

		stream->receive(inMessage);

		logSrv->info("Received: " + inMessage);


		delete stream;
    }
    else
    {
    	logSrv->error("skata");	
    }
}