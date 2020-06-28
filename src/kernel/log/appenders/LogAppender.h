#ifndef LogAppender_h__
#define LogAppender_h__

#include <iostream>
#include <string>

#include "../LogLevel.h"
#include "../LogRecord.h"

using namespace std;

class LogAppender
{
protected:
	LogLevel level;

	virtual void appendOutput(const LogRecord &record) = 0;

public:
	LogAppender(LogLevel level);
	virtual ~LogAppender();

    virtual bool isLevelEnabled(LogLevel level);
    virtual void log(LogLevel level, LogRecord record);

};

#endif // LogAppender_h__
