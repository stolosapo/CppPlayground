#include "LogLevel.h"

#include <string>

using namespace std;

string logLevelToString(LogLevel level)
{
    switch (level)
    {
    case TRACE:
        return "TRACE";
    case DEBUG:
        return "DEBUG";
    case INFO:
        return "INFO";
    case WARN:
        return "WARN";
    case ERROR:
        return "ERROR";
    case FATAL:
        return "FATAL";
    default:
        return "TRACE";
    }
}

LogLevel logLevelFromString(string level)
{
    if (level == "TRACE")
    {
        return TRACE;
    }

    if (level == "DEBUG")
    {
        return DEBUG;
    }

    if (level == "INFO")
    {
        return INFO;
    }

    if (level == "WARN")
    {
        return WARN;
    }

    if (level == "ERROR")
    {
        return ERROR;
    }

    if (level == "FATAL")
    {
        return FATAL;
    }

    return TRACE;
}
