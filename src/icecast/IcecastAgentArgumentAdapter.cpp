#include "IcecastAgentArgumentAdapter.h"

IcecastAgentArgumentAdapter::IcecastAgentArgumentAdapter(ArgumentService* argService) : ArgumentAdapter(argService)
{

}

IcecastAgentArgumentAdapter::~IcecastAgentArgumentAdapter()
{

}

bool IcecastAgentArgumentAdapter::hasAgentConfigFilename() const
{
    return hasArg("icecastagent.config");
}

string IcecastAgentArgumentAdapter::getAgentConfigFilename() const
{
    return getStringValue("icecastagent.config");
}
