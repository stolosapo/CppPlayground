#include "LogAppender.h"

LogAppender::LogAppender(LogLevel level) :
    level(level)
{

}

LogAppender::~LogAppender()
{

}

bool LogAppender::isLevelEnabled(LogLevel level)
{
    return this->level <= level;
}

void LogAppender::log(LogRecord record)
{
    if (!isLevelEnabled(record.getLogLevel()))
    {
        return;
    }

    appendOutput(record);
}
