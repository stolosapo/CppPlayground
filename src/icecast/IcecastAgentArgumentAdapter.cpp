#include "IcecastAgentArgumentAdapter.h"


const string IcecastAgentArgumentAdapter::CONFIG_FILE = "icecastagent.config";

IcecastAgentArgumentAdapter::IcecastAgentArgumentAdapter(ArgumentService* argService) : ArgumentAdapter(argService)
{

}

IcecastAgentArgumentAdapter::~IcecastAgentArgumentAdapter()
{

}

string IcecastAgentArgumentAdapter::help()
{
    return "";
}

void IcecastAgentArgumentAdapter::registerArguments()
{
    registerArg(CONFIG_FILE, "The config file, for the NoiseStreamer Agent");
}

bool IcecastAgentArgumentAdapter::hasAgentConfigFilename() const
{
    return hasArg(CONFIG_FILE);
}

string IcecastAgentArgumentAdapter::getAgentConfigFilename() const
{
    return getStringValue(CONFIG_FILE);
}
