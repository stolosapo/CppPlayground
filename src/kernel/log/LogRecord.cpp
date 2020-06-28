#include "LogRecord.h"

LogRecord::LogRecord(const char* className, LogLevel level, string message, time_t time) :
    className(className),
    level(level),
    message(message),
    time(time)
{

}

LogRecord::LogRecord(const LogRecord &logRecord)
{
    className = logRecord.className;
    level = logRecord.level;
    message = logRecord.message;
    time = logRecord.time;
}

LogRecord::~LogRecord()
{

}

const char* LogRecord::getClassName() const
{
    return className;
}

LogLevel LogRecord::getLogLevel() const
{
    return level;
}

string LogRecord::getLogLevelName() const
{
    return logLevelToString(getLogLevel());
}

string LogRecord::getMessage() const
{
    return message;
}

time_t LogRecord::getTime() const
{
    return time;
}

size_t LogRecord::size() const
{
    int classNameSize = string(className).size();
    int levelSize = getLogLevelName().size();
    int messageSize = message.size();
    int timeSize = 20;

    return classNameSize + levelSize + messageSize + timeSize;
}
