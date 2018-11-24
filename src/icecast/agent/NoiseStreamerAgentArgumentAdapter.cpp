#include "NoiseStreamerAgentArgumentAdapter.h"


const string NoiseStreamerAgentArgumentAdapter::CONFIG_FILE = "nss.agent.config";

NoiseStreamerAgentArgumentAdapter::NoiseStreamerAgentArgumentAdapter(ArgumentService* argService) : ArgumentAdapter(argService)
{

}

NoiseStreamerAgentArgumentAdapter::~NoiseStreamerAgentArgumentAdapter()
{

}

string NoiseStreamerAgentArgumentAdapter::title()
{
    return "Noise Streamer Agent";
}

void NoiseStreamerAgentArgumentAdapter::registerArguments()
{
    registerArg(CONFIG_FILE, "The config file, for the Noise Streamer Agent");
}

bool NoiseStreamerAgentArgumentAdapter::hasAgentConfigFilename() const
{
    return hasArg(CONFIG_FILE);
}

string NoiseStreamerAgentArgumentAdapter::getAgentConfigFilename() const
{
    return getStringValue(CONFIG_FILE);
}
