#include "NoiseStreamerAgentConfig.h"

#include <string>

using namespace std;

NoiseStreamerAgentConfig::NoiseStreamerAgentConfig() : TcpServerConfig(&factory)
{
	this->registerProperties();
}

NoiseStreamerAgentConfig::~NoiseStreamerAgentConfig()
{

}

void NoiseStreamerAgentConfig::registerProperties()
{
	TcpServerConfig::registerProperties();

    this->registerPropertyName(20, "icecast_config", STRING);
}

string NoiseStreamerAgentConfig::getIcecastConfig()
{
    string value = getStringProperty("icecast_config");

    if (value == "")
    {
        return "icecast/icecast.config";
    }

    return value;
}

Model* NoiseStreamerAgentConfig::factory()
{
	return (Model*) new NoiseStreamerAgentConfig;
}
