#include "LogService.h"

#include "../configuration/ConfigLoader.h"
#include "config/LoggerConfig.h"
#include "config/LogAppenderConfig.h"
#include "appenders/LogAppenderFactory.h"

const char* LogService::DEFAULT_CONF_FILENAME = "log/log.conf";

LogService::LogService(ITimeService *timeService):
    ILogService(),
    timeService(timeService)
{
    config = NULL;
}

LogService::~LogService()
{
    if (config != NULL)
    {
        delete config;
    }

    for (int i = 0; i < loggers.size(); i++)
    {
        delete loggers[i];
    }

    loggers.clear();
}

void LogService::init()
{
    // Load config from file
    ConfigLoader<LogServiceConfig> loader(DEFAULT_CONF_FILENAME);
    this->config = loader.load();

    // TODO: This will change to vector
    LoggerConfig* loggerConfig = config->getLogger();
    // TODO: This will change to vector
    LogAppenderConfig* appenderConfig = loggerConfig->getAppender();

    // Create Appenders
    LogAppenderFactory appenderFactory;
    LogAppender* appender = appenderFactory.createFromConfig(appenderConfig);
    vector<LogAppender*> appenders;
    appenders.push_back(appender);

    // Create Loggers
    Logger* logger = new Logger(loggerConfig->getName(), appenders);
    loggers.push_back(logger);
}

void LogService::log(LogLevel level, string message)
{
    // Create a log record
    LogRecord record("", level, message, timeService->rawNow());

    // Log it through all loggers
    for (int i = 0; i < loggers.size(); i++)
    {
        loggers[i]->log(record);
    }
}

void LogService::trace(string message)
{
    log(TRACE, message);
}

void LogService::info(string message)
{
    log(INFO, message);
}

void LogService::debug(string message)
{
    log(DEBUG, message);
}

void LogService::warn(string message)
{
    log(WARN, message);
}

void LogService::error(string message)
{
    log(ERROR, message);
}

void LogService::fatal(string message)
{
    log(FATAL, message);
}
