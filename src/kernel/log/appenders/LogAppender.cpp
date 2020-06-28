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

void LogAppender::log(LogLevel level, LogRecord record)
{
    if (!isLevelEnabled(level))
    {
        return;
    }

    appendOutput(record);
}
