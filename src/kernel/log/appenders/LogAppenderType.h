#ifndef LogAppenderType_h__
#define LogAppenderType_h__

#include <string>

using namespace std;

enum LogAppenderType
{
    CONSOLE = 0,

    ROLLING_FILE = 1
};

string logAppenderTypeToString(LogAppenderType type);
LogAppenderType logAppenderTypeFromString(string type);


#endif // LogAppenderType_h__
