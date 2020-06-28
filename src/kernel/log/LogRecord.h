#ifndef LogRecord_h__
#define LogRecord_h__

#include <iostream>
#include <string>
#include <time.h>

#include "LogLevel.h"

using namespace std;

class LogRecord
{
private:
    const char* className;
    LogLevel level;
    string message;
    time_t time;

public:
	LogRecord(const char* className, LogLevel level, string message, time_t time);
    LogRecord(const LogRecord &logRecord);
	virtual ~LogRecord();

	const char* getClassName() const;
    LogLevel getLogLevel() const;
    string getLogLevelName() const;
    string getMessage() const;
    time_t getTime() const;

    size_t size() const;
};

#endif // LogRecord_h__
