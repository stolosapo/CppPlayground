#ifndef LogRecord_h__
#define LogRecord_h__

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

class LogRecord
{
private:
    const char* className;
    string message;
    time_t time;

public:
	LogRecord(const char* className, string message, time_t time);
    LogRecord(const LogRecord &logRecord);
	virtual ~LogRecord();

	const char* getClassName() const;
    string getMessage() const;
    time_t getTime() const;
};

#endif // LogRecord_h__
