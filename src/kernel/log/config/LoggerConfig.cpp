#include "LoggerConfig.h"

#include <string>

using namespace std;

LoggerConfig::LoggerConfig() : IConfig(&factory)
{
	this->registerProperties();
}

LoggerConfig::~LoggerConfig()
{

}

void LoggerConfig::registerProperties()
{
    this->registerPropertyName(0, "name", STRING);
    this->registerPropertyName(1, "appenders", OBJECT, &LogAppenderConfig::factory);
}

string LoggerConfig::getName()
{
    return getStringProperty("name");
}

LogAppenderConfig* LoggerConfig::getAppender()
{
    return (LogAppenderConfig*) getObjectProperty("appenders");
}

Model* LoggerConfig::factory()
{
	return (Model*) new LoggerConfig;
}
