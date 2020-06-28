#ifndef LogService_h__
#define LogService_h__

#include <iostream>
#include <string>
#include <vector>

#include "ILogService.h"
#include "Logger.h"
#include "config/LogServiceConfig.h"
#include "../time/ITimeService.h"

using namespace std;

class LogService : public ILogService
{
private:
    static const char* DEFAULT_CONF_FILENAME;

    ITimeService *timeService;
    LogServiceConfig* config;
    vector<Logger*> loggers;

    void log(LogLevel level, string message);

public:
	LogService(ITimeService *timeService);
	virtual ~LogService();

     void init();

	virtual void trace(string message);
	virtual void info(string message);
	virtual void debug(string message);
	virtual void warn(string message);
	virtual void error(string message);
	virtual void fatal(string message);

};

#endif // LogService_h__
