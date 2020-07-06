#include "ConsoleAppender.h"
#include "../../console/Console.h"
#include "../../definitions/Colors.h"

#include <iostream>
#include <stdio.h>

using namespace std;

ConsoleAppender::ConsoleAppender(LogLevel level, string format, bool useColor) :
	LogAppender(level),
    format(format),
    useColor(useColor)
{

}

ConsoleAppender::~ConsoleAppender()
{

}

void ConsoleAppender::printColor(string COLOR)
{
    if (this->useColor)
    {
        Console::outString(COLOR);
    }
}

string ConsoleAppender::levelToColor(LogLevel level)
{
    switch (level)
    {
    case TRACE:
        return BOLDGREEN;
    case DEBUG:
        return BOLDBLUE;
    case INFO:
        return BOLDYELLOW;
    case WARN:
        return BOLDMAGENTA;
    case ERROR:
        return BOLDRED;
    case FATAL:
        return BOLDRED;
    default:
        return RESET;
    }
}

string ConsoleAppender::formatMessage(const LogRecord &record)
{
    size_t recordSize = record.size();
    size_t formatSize = string(format).size();
    size_t bufferSize = recordSize + formatSize;

    char* buffer = new char[bufferSize];

    int sz = sprintf(
        buffer,
        format.c_str(),
        record.getLogLevelName().c_str(),
        record.getClassName(),
        record.getMessage().c_str()
    );

    string mess = string(buffer);

    delete[] buffer;

    return mess;
}

void ConsoleAppender::appendOutput(const LogRecord &record)
{
    printColor(levelToColor(record.getLogLevel()));
    Console::outStringln(formatMessage(record));
    printColor(RESET);
}
