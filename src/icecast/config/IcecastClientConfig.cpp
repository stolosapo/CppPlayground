#include "IcecastClientConfig.h"


IcecastClientConfig::IcecastClientConfig() : IConfig(&factory)
{
	this->registerProperties();
}

IcecastClientConfig::~IcecastClientConfig()
{

}

void IcecastClientConfig::registerProperties()
{
	registerPropertyName(1, "hostname", Property::STRING);
	registerPropertyName(2, "port", Property::STRING);
	registerPropertyName(3, "username", Property::STRING);
	registerPropertyName(4, "password", Property::STRING);
	registerPropertyName(5, "protocol", Property::STRING);
	registerPropertyName(6, "mountpoint", Property::STRING);
	registerPropertyName(7, "name", Property::STRING);
	registerPropertyName(8, "genre", Property::STRING);
	registerPropertyName(9, "description", Property::STRING);
	registerPropertyName(10, "url", Property::STRING);
	registerPropertyName(11, "public", Property::STRING);
	registerPropertyName(12, "bitrate", Property::STRING);
	registerPropertyName(13, "samplerate", Property::STRING);
	registerPropertyName(14, "channels", Property::STRING);
	registerPropertyName(15, "playlist", Property::STRING);
	registerPropertyName(16, "random", Property::BOOL);
	registerPropertyName(17, "repeat", Property::BOOL);
}

Model* IcecastClientConfig::factory()
{
	return (Model*) new IcecastClientConfig;
}

string IcecastClientConfig::getHostname()
{
	return getStringProperty("hostname");
}

string IcecastClientConfig::getPort()
{
	return getStringProperty("port");
}

string IcecastClientConfig::getUsername()
{
	return getStringProperty("username");
}

string IcecastClientConfig::getPassword()
{
	return getStringProperty("password");
}

string IcecastClientConfig::getProtocol()
{
	return getStringProperty("protocol");
}

string IcecastClientConfig::getMountpoint()
{
	return getStringProperty("mountpoint");
}

string IcecastClientConfig::getName()
{
	return getStringProperty("name");
}

string IcecastClientConfig::getGenre()
{
	return getStringProperty("genre");
}

string IcecastClientConfig::getDescription()
{
	return getStringProperty("description");
}

string IcecastClientConfig::getUrl()
{
	return getStringProperty("url");
}

string IcecastClientConfig::getPublic()
{
	return getStringProperty("public");
}

string IcecastClientConfig::getBitrate()
{
	return getStringProperty("bitrate");
}

string IcecastClientConfig::getSamplerate()
{
	return getStringProperty("samplerate");
}

string IcecastClientConfig::getChannels()
{
	return getStringProperty("channels");
}

string IcecastClientConfig::getPlaylist()
{
	return getStringProperty("playlist");
}

bool IcecastClientConfig::getRandom()
{
	return getBoolProperty("random");
}

bool IcecastClientConfig::getRepeat()
{
	return getBoolProperty("repeat");
}