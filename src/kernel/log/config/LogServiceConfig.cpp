#include "LogServiceConfig.h"

#include <string>

using namespace std;

LogServiceConfig::LogServiceConfig() : IConfig(&factory)
{
	this->registerProperties();
}

LogServiceConfig::~LogServiceConfig()
{

}

void LogServiceConfig::registerProperties()
{
    this->registerPropertyName(0, "loggers", OBJECT, &LoggerConfig::factory);
}

LoggerConfig* LogServiceConfig::getLogger()
{
    return (LoggerConfig*) getObjectProperty("loggers");
}

Model* LogServiceConfig::factory()
{
	return (Model*) new LogServiceConfig;
}
