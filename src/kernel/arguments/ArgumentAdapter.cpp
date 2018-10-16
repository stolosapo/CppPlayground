#include "ArgumentAdapter.h"

ArgumentAdapter::ArgumentAdapter(ArgumentService* argService) : argService(argService)
{

}

ArgumentAdapter::~ArgumentAdapter()
{

}

bool ArgumentAdapter::hasArg(string name) const
{
    return argService->hasArg(name);
}

string ArgumentAdapter::getStringValue(string name) const
{
    return argService->getStringValue(name);
}

int ArgumentAdapter::getIntValue(string name) const
{
    return argService->getIntValue(name);
}

bool ArgumentAdapter::getBoolValue(string name) const
{
    return argService->getBoolValue(name);
}
