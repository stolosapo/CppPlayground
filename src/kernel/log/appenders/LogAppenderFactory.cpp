#include "LogAppenderFactory.h"

#include "ConsoleAppender.h"
#include "FileAppender.h"

LogAppenderFactory::LogAppenderFactory()
{

}

LogAppenderFactory::~LogAppenderFactory()
{

}

LogAppender* LogAppenderFactory::createFromConfig(LogAppenderConfig *config)
{
    LogAppenderType type = config->getAppenderType();
    LogLevel level = config->getLogLevel();

    string filename = config->getFilename();

    switch (config->getAppenderType())
    {
    case CONSOLE:
        return (LogAppender*) new ConsoleAppender(level);

    case ROLLING_FILE:
        return (LogAppender*) new FileAppender(level, filename);

    default:
        return (LogAppender*) new ConsoleAppender(level);
    }
}
