#ifndef ConsoleAppender_h__
#define ConsoleAppender_h__

#include <iostream>
#include <string>

#include "../LogLevel.h"
#include "LogAppender.h"

using namespace std;

class ConsoleAppender: public LogAppender
{
private:
    string format;
    bool useColor;

    void printColor(string COLOR);
    string levelToColor(LogLevel level);
    string formatMessage(const LogRecord &record);

protected:
	virtual void appendOutput(const LogRecord &record);

public:
	ConsoleAppender(LogLevel level, string format, bool useColor);
	virtual ~ConsoleAppender();

};

#endif // ConsoleAppender_h__
