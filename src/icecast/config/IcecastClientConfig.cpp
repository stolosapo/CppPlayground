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
	registerPropertyName(1, "hostname", STRING);
	registerPropertyName(2, "port", STRING);
	registerPropertyName(3, "username", STRING);
	registerPropertyName(4, "password", STRING);
	registerPropertyName(5, "protocol", STRING);
	registerPropertyName(6, "mountpoint", STRING);
	registerPropertyName(7, "name", STRING);
	registerPropertyName(8, "genre", STRING);
	registerPropertyName(9, "description", STRING);
	registerPropertyName(10, "url", STRING);
	registerPropertyName(11, "public", STRING);
	registerPropertyName(12, "bitrate", STRING);
	registerPropertyName(13, "samplerate", STRING);
	registerPropertyName(14, "channels", STRING);
	registerPropertyName(15, "playlist", STRING);
	registerPropertyName(16, "history", STRING);
	registerPropertyName(17, "metadata", STRING);
	registerPropertyName(18, "repeat", BOOL);
	registerPropertyName(19, "strategy", STRING);
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

string IcecastClientConfig::getHistory()
{
	return getStringProperty("history", "playlist.history.pls");
}
string IcecastClientConfig::getMetadata()
{
	return getStringProperty("metadata", "playlist.metadata.json");
}

bool IcecastClientConfig::getRepeat()
{
	return getBoolProperty("repeat");
}

string IcecastClientConfig::getStrategy()
{
	return getStringProperty("strategy", "");
}

PlaylistStrategyType IcecastClientConfig::getStrategyType()
{
	string strategy = getStrategy();

	if (strategy == "SIMPLE")
	{
		return SIMPLE;
	}

	if (strategy == "RANDOM")
	{
		return RANDOM;
	}

	if (strategy == "RANDOM_ONCE")
	{
		return RANDOM_ONCE;
	}

	return NONE;
}
