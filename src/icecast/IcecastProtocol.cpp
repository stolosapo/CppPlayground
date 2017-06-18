#include <stdio.h>
#include <cstring>

#include "IcecastProtocol.h"

#include "../shared/Base64.h"

using namespace std;


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

const char* IcecastProtocol::NEW_LINE = "\r\n";

const char* IcecastProtocol::USER_AGENT = "NoiseStreamer";
const char* IcecastProtocol::CONTENT_TYPE = "audio/mpeg";


IcecastProtocol::IcecastProtocol(IcecastClientConfig *config)
{
	this->config = config;
}

IcecastProtocol::~IcecastProtocol()
{

}

string IcecastProtocol::getHttpBasicAuthorization(string user, string password)
{
	string auth = user + ":" + password;
	int authLen = auth.length() + 1;

	unsigned char* buff = new unsigned char[authLen];
	memcpy(buff, auth.c_str(), authLen);
	
	string encodedAuth = Base64::encode(buff, auth.length());

	return encodedAuth;
}

string IcecastProtocol::connectionRequest()
{
	string request;

	string hostname = config->getHostname();
	string port = config->getPort();
	
	string mountpoint = config->getMountpoint();
	string password = config->getPassword();

	string auth = getHttpBasicAuthorization(mountpoint, password);

	string name = config->getName();
	string description = config->getDescription();
	string genre = config->getGenre();
	
	string _public = config->getPublic();
	string url = config->getUrl();

	string bitrate = config->getBitrate();	
	string samplerate = config->getSamplerate();
	string channels = config->getChannels();

	request = "PUT " + mountpoint + " HTTP/1.1" + NEW_LINE +
		"Authorization: Basic " + auth + NEW_LINE +
		"User-Agent: " + USER_AGENT + NEW_LINE +
		"Content-Type: " + CONTENT_TYPE + NEW_LINE +
		"ice-name: " + name + NEW_LINE +
		"ice-public: " + _public + NEW_LINE +
		"ice-url: " + url + NEW_LINE +
		"ice-genre: " + genre + NEW_LINE +
		"ice-bitrate: " + bitrate + NEW_LINE +
		"ice-audio-info: samplerate=" + samplerate + 
			";bitrate=" + bitrate + 
			";channels=" + channels + NEW_LINE +
		"ice-description: " + description + NEW_LINE + 
		NEW_LINE;

	return request;
}

string IcecastProtocol::changeMetadataRequest(string newTitle)
{
	return "";
}

string IcecastProtocol::validateResponse(string responce)
{
	return "";
}