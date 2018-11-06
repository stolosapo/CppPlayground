#include "IcecastAgentClientArgumentAdapter.h"

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

bool IcecastAgentClientArgumentAdapter::hasAgentClientConfigFilename() const
{
    return hasArg("icecastagentclient.config");
}

string IcecastAgentClientArgumentAdapter::getAgentClientConfigFilename() const
{
    return getStringValue("icecastagentclient.config");
}
