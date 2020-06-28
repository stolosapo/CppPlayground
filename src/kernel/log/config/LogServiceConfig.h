#ifndef LogServiceConfig_h__
#define LogServiceConfig_h__

#include <string>

#include "../../configuration/IConfig.h"
#include "LoggerConfig.h"

using namespace std;

class LogServiceConfig : public IConfig
{
public:
    LogServiceConfig();
    virtual ~LogServiceConfig();

    static Model* factory();

    LoggerConfig* getLogger();

protected:
    virtual void registerProperties();

};

#endif // LogServiceConfig_h__
