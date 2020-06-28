#include "Logger.h"

Logger::Logger(string name, vector<LogAppender*> appenders) :
    name(name),
    appenders(appenders)
{

}

Logger::~Logger()
{

}

string Logger::getName() const
{
    return name;
}

void Logger::log(LogLevel level, LogRecord record)
{
    for (int i = 0; i < appenders.size(); ++i)
	{
        appenders[i]->log(level, record);
    }
}
