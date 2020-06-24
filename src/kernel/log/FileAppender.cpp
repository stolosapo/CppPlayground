#include "FileAppender.h"
#include "../utils/FileHelper.h"

FileAppender::FileAppender(
    const char* className,
    LogLevel level,
    string filename
    ) :
	LogAppender(className, level),
    filename(filename)
{

}

FileAppender::~FileAppender()
{

}

string FileAppender::formatMessage(string message)
{
    const char* format = "[DATETIME] %s %s %s";
    char *formattedMessage = new char;

    sprintf(formattedMessage, format, levelToString(), className, message);

    string mess = string(formattedMessage);

    delete formattedMessage;

    return mess;
}

void FileAppender::rollFileIfNeeded()
{

}

void FileAppender::appendOutput(string message)
{
    rollFileIfNeeded();
    FileHelper::appendLineFileToFile(filename.c_str(), formatMessage(message));
}
