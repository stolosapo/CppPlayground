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
	registerPropertyName(3, "password", Property::STRING);
	registerPropertyName(4, "protocol", Property::STRING);
	registerPropertyName(5, "mountpoint", Property::STRING);
	registerPropertyName(6, "name", Property::STRING);
	registerPropertyName(7, "genre", Property::STRING);
	registerPropertyName(8, "description", Property::STRING);
	registerPropertyName(9, "url", Property::STRING);
	registerPropertyName(10, "public", Property::STRING);
	registerPropertyName(11, "bitrate", Property::STRING);
	registerPropertyName(12, "samplerate", Property::STRING);
	registerPropertyName(13, "channels", Property::STRING);
	registerPropertyName(14, "playlist", Property::STRING);
	registerPropertyName(15, "random", Property::BOOL);
	registerPropertyName(16, "repeat", Property::BOOL);
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