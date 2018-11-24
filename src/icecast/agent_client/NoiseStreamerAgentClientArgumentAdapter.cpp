#include "NoiseStreamerAgentClientArgumentAdapter.h"


const string NoiseStreamerAgentClientArgumentAdapter::CONFIG_FILE = "icecastagentclient.config";

NoiseStreamerAgentClientArgumentAdapter::NoiseStreamerAgentClientArgumentAdapter(ArgumentService* argService) : ArgumentAdapter(argService)
{

}

NoiseStreamerAgentClientArgumentAdapter::~NoiseStreamerAgentClientArgumentAdapter()
{

}

string NoiseStreamerAgentClientArgumentAdapter::title()
{
    return "NoiseStreamer Agent Client";
}

void NoiseStreamerAgentClientArgumentAdapter::registerArguments()
{
    registerArg(CONFIG_FILE, "The config file, for the NoiseStreamer Agent Client");
}

bool NoiseStreamerAgentClientArgumentAdapter::hasAgentClientConfigFilename() const
{
    return hasArg(CONFIG_FILE);
}

string NoiseStreamerAgentClientArgumentAdapter::getAgentClientConfigFilename() const
{
    return getStringValue(CONFIG_FILE);
}
