#include "NoiseStreamerAgentClientArgumentAdapter.h"


const string NoiseStreamerAgentClientArgumentAdapter::CONFIG_FILE = "nss.client.config";

NoiseStreamerAgentClientArgumentAdapter::NoiseStreamerAgentClientArgumentAdapter(ArgumentService* argService) : ArgumentAdapter(argService)
{

}

NoiseStreamerAgentClientArgumentAdapter::~NoiseStreamerAgentClientArgumentAdapter()
{

}

string NoiseStreamerAgentClientArgumentAdapter::title()
{
    return "Noise Streamer Client";
}

void NoiseStreamerAgentClientArgumentAdapter::registerArguments()
{
    registerArg(CONFIG_FILE, "The config file, for the Noise Streamer Client");
}

bool NoiseStreamerAgentClientArgumentAdapter::hasAgentClientConfigFilename() const
{
    return hasArg(CONFIG_FILE);
}

string NoiseStreamerAgentClientArgumentAdapter::getAgentClientConfigFilename() const
{
    return getStringValue(CONFIG_FILE);
}
