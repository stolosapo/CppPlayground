#include "FileAppender.h"
#include "../../utils/FileHelper.h"

#include <stdio.h>

const char* FileAppender::DEFAULT_FILENAME = "output.log";

FileAppender::FileAppender(
    LogLevel level,
    string filename
    ) :
	LogAppender(level),
    filename(filename)
{
    if (filename == "")
    {
        this->filename = string(DEFAULT_FILENAME);
    }
}

FileAppender::~FileAppender()
{

}

string FileAppender::formatMessage(const LogRecord &record)
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

void FileAppender::rollFileIfNeeded()
{

}

void FileAppender::appendOutput(const LogRecord &record)
{
    rollFileIfNeeded();
    FileHelper::appendLineFileToFile(filename.c_str(), formatMessage(record));
}
