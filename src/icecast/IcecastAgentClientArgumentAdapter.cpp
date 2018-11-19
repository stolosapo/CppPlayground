#include "IcecastAgentClientArgumentAdapter.h"


const string IcecastAgentClientArgumentAdapter::CONFIG_FILE = "icecastagentclient.config";

IcecastAgentClientArgumentAdapter::IcecastAgentClientArgumentAdapter(ArgumentService* argService) : ArgumentAdapter(argService)
{

}

IcecastAgentClientArgumentAdapter::~IcecastAgentClientArgumentAdapter()
{

}

string IcecastAgentClientArgumentAdapter::help()
{
    return "";
}

string IcecastAgentClientArgumentAdapter::title()
{
    return "NoiseStreamer Agent Client";
}

void IcecastAgentClientArgumentAdapter::registerArguments()
{
    registerArg(CONFIG_FILE, "The config file, for the NoiseStreamer Agent Client");
}

bool IcecastAgentClientArgumentAdapter::hasAgentClientConfigFilename() const
{
    return hasArg(CONFIG_FILE);
}

string IcecastAgentClientArgumentAdapter::getAgentClientConfigFilename() const
{
    return getStringValue(CONFIG_FILE);
}
