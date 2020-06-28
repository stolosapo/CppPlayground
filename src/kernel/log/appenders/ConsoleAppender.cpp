#include "ConsoleAppender.h"
#include "../../console/Console.h"

#include <iostream>
#include <stdio.h>

using namespace std;

ConsoleAppender::ConsoleAppender(LogLevel level) :
	LogAppender(level)
{

}

ConsoleAppender::~ConsoleAppender()
{

}

string ConsoleAppender::formatMessage(const LogRecord &record)
{
    const char* format = "DATETIME [%s]: %s %s";

    size_t recordSize = record.size();
    size_t formatSize = string(format).size();
    size_t bufferSize = recordSize + formatSize;

    char* buffer = new char[bufferSize];

    int sz = sprintf(
        buffer,
        format,
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
    Console::outStringln(formatMessage(record));
}
