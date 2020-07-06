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
    string format = config->getFormat();
    LogLevel level = config->getLogLevel();
    bool useColor = config->useColor();

    string filename = config->getFilename();

    switch (config->getAppenderType())
    {
    case CONSOLE:
        return (LogAppender*) new ConsoleAppender(level, format, useColor);

    case ROLLING_FILE:
        return (LogAppender*) new FileAppender(level, filename);

    default:
        return (LogAppender*) new ConsoleAppender(level, format, useColor);
    }
}
