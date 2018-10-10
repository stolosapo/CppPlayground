#include "ArgumentService.h"

#include "ArgParser.h"

ArgumentService::ArgumentService(int argc, char* argv[])
    : IService()
{
    ArgParser parser;

    ArgumentList list = parser.parse(argc, argv);

    this->arguments = &list;
}

ArgumentService::~ArgumentService()
{
    if (arguments != NULL)
    {
        delete arguments;
    }
}

bool ArgumentService::hasArg(string name)
{
    return false;
}

string ArgumentService::getStringValue(string name) const
{
    return "";
}

int ArgumentService::getIntValue(string name) const
{
    return -1;
}

bool ArgumentService::getBoolValue(string name) const
{
    return false;
}
