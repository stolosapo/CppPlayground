#include "NoiseStreamerConfig.h"


NoiseStreamerConfig::NoiseStreamerConfig() : IConfig(&factory)
{
	this->registerProperties();
}

NoiseStreamerConfig::~NoiseStreamerConfig()
{

}

void NoiseStreamerConfig::registerProperties()
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

Model* NoiseStreamerConfig::factory()
{
	return (Model*) new NoiseStreamerConfig;
}

string NoiseStreamerConfig::getHostname()
{
	return getStringProperty("hostname");
}

string NoiseStreamerConfig::getPort()
{
	return getStringProperty("port");
}

string NoiseStreamerConfig::getUsername()
{
	return getStringProperty("username");
}

string NoiseStreamerConfig::getPassword()
{
	return getStringProperty("password");
}

string NoiseStreamerConfig::getProtocol()
{
	return getStringProperty("protocol");
}

string NoiseStreamerConfig::getMountpoint()
{
	return getStringProperty("mountpoint");
}

string NoiseStreamerConfig::getName()
{
	return getStringProperty("name");
}

string NoiseStreamerConfig::getGenre()
{
	return getStringProperty("genre");
}

string NoiseStreamerConfig::getDescription()
{
	return getStringProperty("description");
}

string NoiseStreamerConfig::getUrl()
{
	return getStringProperty("url");
}

string NoiseStreamerConfig::getPublic()
{
	return getStringProperty("public");
}

string NoiseStreamerConfig::getBitrate()
{
	return getStringProperty("bitrate");
}

string NoiseStreamerConfig::getSamplerate()
{
	return getStringProperty("samplerate");
}

string NoiseStreamerConfig::getChannels()
{
	return getStringProperty("channels");
}

string NoiseStreamerConfig::getPlaylist()
{
	return getStringProperty("playlist");
}

string NoiseStreamerConfig::getHistory()
{
	return getStringProperty("history", "playlist.history.pls");
}
string NoiseStreamerConfig::getMetadata()
{
	return getStringProperty("metadata", "playlist.metadata.json");
}

bool NoiseStreamerConfig::getRepeat()
{
	return getBoolProperty("repeat");
}

string NoiseStreamerConfig::getStrategy()
{
	return getStringProperty("strategy", "");
}

PlaylistStrategyType NoiseStreamerConfig::getStrategyType()
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
