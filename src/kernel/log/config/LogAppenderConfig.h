#ifndef LogAppenderConfig_h__
#define LogAppenderConfig_h__

#include <string>

#include "../../configuration/IConfig.h"
#include "../appenders/LogAppenderType.h"
#include "../LogLevel.h"

using namespace std;

class LogAppenderConfig : public IConfig
{
public:
    LogAppenderConfig();
    virtual ~LogAppenderConfig();

    static Model* factory();

    string getType();
    LogAppenderType getAppenderType();

    string getLevel();
    LogLevel getLogLevel();

    string getFilename();

protected:
    virtual void registerProperties();

};

#endif // LogAppenderConfig_h__
