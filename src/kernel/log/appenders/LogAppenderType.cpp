#include "LogAppenderType.h"

#include <string>

using namespace std;

string logAppenderTypeToString(LogAppenderType type)
{
    switch (type)
    {
    case CONSOLE:
        return "CONSOLE";
    case ROLLING_FILE:
        return "ROLLING_FILE";
    default:
        return "CONSOLE";
    }
}

LogAppenderType logAppenderTypeFromString(string type)
{
    if (type == "CONSOLE")
    {
        return CONSOLE;
    }

    if (type == "ROLLING_FILE")
    {
        return ROLLING_FILE;
    }

    return CONSOLE;
}
