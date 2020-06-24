#ifndef ConsoleAppender_h__
#define ConsoleAppender_h__

#include <iostream>
#include <string>

#include "LogLevel.h"
#include "LogAppender.h"

using namespace std;

class ConsoleAppender: public LogAppender
{
private:
    string formatMessage(string message);

protected:
	virtual void appendOutput(string message);

public:
	ConsoleAppender(const char* className, LogLevel level);
	virtual ~ConsoleAppender();

};

#endif // ConsoleAppender_h__
