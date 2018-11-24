#include "NoiseStreamerAgentArgumentAdapter.h"


const string NoiseStreamerAgentArgumentAdapter::CONFIG_FILE = "icecastagent.config";

NoiseStreamerAgentArgumentAdapter::NoiseStreamerAgentArgumentAdapter(ArgumentService* argService) : ArgumentAdapter(argService)
{

}

NoiseStreamerAgentArgumentAdapter::~NoiseStreamerAgentArgumentAdapter()
{

}

string NoiseStreamerAgentArgumentAdapter::title()
{
    return "NoiseStreamer Agent";
}

void NoiseStreamerAgentArgumentAdapter::registerArguments()
{
    registerArg(CONFIG_FILE, "The config file, for the NoiseStreamer Agent");
}

bool NoiseStreamerAgentArgumentAdapter::hasAgentConfigFilename() const
{
    return hasArg(CONFIG_FILE);
}

string NoiseStreamerAgentArgumentAdapter::getAgentConfigFilename() const
{
    return getStringValue(CONFIG_FILE);
}
