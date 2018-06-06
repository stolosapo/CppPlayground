#ifndef LogAppender_h__
#define LogAppender_h__

#include <iostream>
#include <string>

#include "LogLevel.h"

using namespace std;

class LogAppender
{
private:
	const char* className;
	LogLevel level;

protected:
	virtual void appendOutput(const char* message) = 0;

public:
	LogAppender(const char* className, LogLevel level);
	virtual ~LogAppender();

	virtual bool isTraceEnabled();
	virtual void trace(const char* message);

	virtual bool isDebugEnabled();
	virtual void debug(const char* message);

	virtual bool isInfoEnabled();
	virtual void info(const char* message);

	virtual bool isWarnEnabled();
	virtual void warn(const char* message);

	virtual bool isErrorEnabled();
	virtual void error(const char* message);

	virtual bool isFatalEnabled();
	virtual void fatal(const char* message);
};

#endif // LogAppender_h__