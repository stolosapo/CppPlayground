#include "ArgumentService.h"

#include "ArgParser.h"
#include "../converter/Convert.h"

ArgumentService::ArgumentService(int argc, char* argv[])
    : IService()
{
    ArgParser parser;

    ArgumentList list = parser.parse(argc, argv);



    this->arguments = static_cast<ArgumentList*>(new ArgumentList(list));
}

ArgumentService::~ArgumentService()
{
    if (arguments != NULL)
    {
        delete arguments;
    }
}

bool ArgumentService::hasArg(string name) const
{
    return arguments->exist(name);
}

string ArgumentService::getStringValue(string name) const
{
    return arguments->get(name);
}

int ArgumentService::getIntValue(string name) const
{
    string value = getStringValue(name);

    if (value == "")
    {
        return 0;
    }

    return Convert<int>::StringToNumber(value);
}

bool ArgumentService::getBoolValue(string name) const
{
    string value = getStringValue(name);

    if (value == "true")
    {
        return true;
    }

    return false;
}
