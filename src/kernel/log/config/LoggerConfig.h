#ifndef LoggerConfig_h__
#define LoggerConfig_h__

#include <string>

#include "../../configuration/IConfig.h"
#include "LogAppenderConfig.h"

using namespace std;

class LoggerConfig : public IConfig
{
public:
    LoggerConfig();
    virtual ~LoggerConfig();

    static Model* factory();

    string getName();
    LogAppenderConfig* getAppender();

protected:
    virtual void registerProperties();

};

#endif // LoggerConfig_h__
