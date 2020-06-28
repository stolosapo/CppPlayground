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

void FileAppender::rollFileIfNeeded()
{

}

void FileAppender::appendOutput(const LogRecord &record)
{
    rollFileIfNeeded();
    FileHelper::appendLineFileToFile(filename.c_str(), formatMessage(record));
}
