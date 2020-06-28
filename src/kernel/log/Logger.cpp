#include "Logger.h"

Logger::Logger(string name, vector<LogAppender*> appenders) :
    name(name),
    appenders(appenders)
{

}

Logger::~Logger()
{
    for (int i = 0; i < appenders.size(); i++)
    {
        delete appenders[i];
    }

    appenders.clear();
}

string Logger::getName() const
{
    return name;
}

void Logger::log(LogRecord record)
{
    for (int i = 0; i < appenders.size(); ++i)
	{
        appenders[i]->log(record);
    }
}
