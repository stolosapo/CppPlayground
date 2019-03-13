#include "ArgumentAdapter.h"

#include "../utils/StringHelper.h"

ArgumentAdapter::ArgumentAdapter(ArgumentService* argService) : argService(argService)
{

}

ArgumentAdapter::~ArgumentAdapter()
{
    registeredArgs.clear();
}

bool ArgumentAdapter::argExist(const string& name) const
{
	return registeredArgs.find(name) != registeredArgs.end();
}

void ArgumentAdapter::registerArg(string name, string description)
{
    if (argExist(name))
    {
        return;
    }

    registeredArgs[name] = description;
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

string ArgumentAdapter::help()
{
    string strTitle = title();
    int titleSize = strTitle.size();

    string h = strTitle + "\n";

    h += StringHelper::pad("=", titleSize) + "\n\n";

    for (map<string, string>::iterator it = registeredArgs.begin();
		it != registeredArgs.end();
		++it)
    {
        h += "  --" + it->first + "\t\t" + it->second + "\n";
    }

    h += "\n";

    return h;
}
