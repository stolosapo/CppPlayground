#include "LogAppender.h"

LogAppender::LogAppender(const char* className, LogLevel level) : 
	className(className),
	level(level)
{

}

LogAppender::~LogAppender()
{

}

bool LogAppender::isTraceEnabled()
{
	return level <= TRACE;
}

void LogAppender::trace(const char* message)
{
	if (!isTraceEnabled())
	{
		return;
	}

	appendOutput(message);
}

bool LogAppender::isDebugEnabled()
{
	return level <= DEBUG;
}

void LogAppender::debug(const char* message)
{
	if (!isDebugEnabled())
	{
		return;
	}

	appendOutput(message);
}

bool LogAppender::isInfoEnabled()
{
	return level <= INFO;
}

void LogAppender::info(const char* message)
{
	if (!isInfoEnabled())
	{
		return;
	}

	appendOutput(message);
}

bool LogAppender::isWarnEnabled()
{
	return level <= WARN;
}

void LogAppender::warn(const char* message)
{
	if (!isWarnEnabled())
	{
		return;
	}

	appendOutput(message);
}


bool LogAppender::isErrorEnabled()
{
	return level <= ERROR;
}

void LogAppender::error(const char* message)
{
	if (!isErrorEnabled())
	{
		return;
	}

	appendOutput(message);
}

bool LogAppender::isFatalEnabled()
{
	return level <= FATAL;
}

void LogAppender::fatal(const char* message)
{
	if (!isFatalEnabled())
	{
		return;
	}

	appendOutput(message);
}