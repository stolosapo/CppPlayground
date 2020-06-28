#ifndef FileAppender_h__
#define FileAppender_h__

#include <iostream>
#include <string>

#include "../LogLevel.h"
#include "LogAppender.h"

using namespace std;

class FileAppender: public LogAppender
{
private:
    static const char* DEFAULT_FILENAME;

    string filename;

    string formatMessage(const LogRecord &record);

protected:
    virtual void rollFileIfNeeded();
	virtual void appendOutput(const LogRecord &record);

public:
	FileAppender(LogLevel level, string filename);
	virtual ~FileAppender();

};

#endif // FileAppender_h__
