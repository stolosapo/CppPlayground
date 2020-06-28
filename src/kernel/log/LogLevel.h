#ifndef LogLevel_h__
#define LogLevel_h__

#include <string>

using namespace std;

enum LogLevel
{
    TRACE = 0,

    DEBUG = 1,

    INFO = 2,

    WARN = 3,

    ERROR = 4,

    FATAL = 5
};

string logLevelToString(LogLevel level);
LogLevel logLevelFromString(string level);


#endif // LogLevel_h__
