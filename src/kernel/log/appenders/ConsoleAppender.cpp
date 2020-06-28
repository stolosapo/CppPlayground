#include "ConsoleAppender.h"
#include "../../console/Console.h"

#include <stdio.h>

ConsoleAppender::ConsoleAppender(LogLevel level) :
	LogAppender(level)
{

}

ConsoleAppender::~ConsoleAppender()
{

}

string ConsoleAppender::formatMessage(const LogRecord &record)
{
    const char* format = "[DATETIME] %s %s %s";
    char *formattedMessage = new char;

    sprintf(
        formattedMessage,
        format,
        logLevelToString(level),
        record.getClassName(),
        record.getMessage()
    );

    string mess = string(formattedMessage);

    delete formattedMessage;

    return mess;
}

void ConsoleAppender::appendOutput(const LogRecord &record)
{
    Console::outStringln(formatMessage(record));
}
