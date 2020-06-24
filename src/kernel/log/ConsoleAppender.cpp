#include "ConsoleAppender.h"
#include "../console/Console.h"

ConsoleAppender::ConsoleAppender(const char* className, LogLevel level) :
	LogAppender(className, level)
{

}

ConsoleAppender::~ConsoleAppender()
{

}

string ConsoleAppender::formatMessage(string message)
{
    const char* format = "[DATETIME] %s %s %s";
    char *formattedMessage = new char;

    sprintf(formattedMessage, format, levelToString(), className, message);

    string mess = string(formattedMessage);

    delete formattedMessage;

    return mess;
}

void ConsoleAppender::appendOutput(string message)
{
    Console::outStringln(formatMessage(message));
}
