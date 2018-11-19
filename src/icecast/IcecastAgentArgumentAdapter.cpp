#include "IcecastAgentArgumentAdapter.h"

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

void IcecastAgentArgumentAdapter::registerArguments() const
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
