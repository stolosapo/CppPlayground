#include "LogAppenderConfig.h"

#include <string>

using namespace std;

LogAppenderConfig::LogAppenderConfig() : IConfig(&factory)
{
	this->registerProperties();
}

LogAppenderConfig::~LogAppenderConfig()
{

}

void LogAppenderConfig::registerProperties()
{
    this->registerPropertyName(0, "type", STRING);
    this->registerPropertyName(1, "level", STRING);
    this->registerPropertyName(2, "format", STRING);
    this->registerPropertyName(3, "filename", STRING);
    this->registerPropertyName(4, "use_color", BOOL);
}

string LogAppenderConfig::getType()
{
    return getStringProperty("type");
}

LogAppenderType LogAppenderConfig::getAppenderType()
{
    string type = getType();
    return logAppenderTypeFromString(type);
}

string LogAppenderConfig::getLevel()
{
    return getStringProperty("level");
}

LogLevel LogAppenderConfig::getLogLevel()
{
    string level = getLevel();
    return logLevelFromString(level);
}

string LogAppenderConfig::getFormat()
{
    return getStringProperty("format");
}

string LogAppenderConfig::getFilename()
{
    return getStringProperty("filename");
}

bool LogAppenderConfig::useColor()
{
    return getBoolProperty("use_color");
}

Model* LogAppenderConfig::factory()
{
	return (Model*) new LogAppenderConfig;
}
