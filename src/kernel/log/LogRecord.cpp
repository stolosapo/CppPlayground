#include "LogRecord.h"

LogRecord::LogRecord(const char* className, string message, time_t time) :
    className(className),
    message(message),
    time(time)
{

}

LogRecord::LogRecord(const LogRecord &logRecord)
{
    className = logRecord.className;
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

string LogRecord::getMessage() const
{
    return message;
}

time_t LogRecord::getTime() const
{
    return time;
}
