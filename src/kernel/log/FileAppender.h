#ifndef FileAppender_h__
#define FileAppender_h__

#include <iostream>
#include <string>

#include "LogLevel.h"
#include "LogAppender.h"

using namespace std;

class FileAppender: public LogAppender
{
private:
    string filename;

    string formatMessage(string message);

protected:
    virtual void rollFileIfNeeded();
	virtual void appendOutput(string message);

public:
	FileAppender(const char* className, LogLevel level, string filename);
	virtual ~FileAppender();

};

#endif // FileAppender_h__
