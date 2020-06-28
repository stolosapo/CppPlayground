#ifndef Logger_h__
#define Logger_h__

#include <iostream>
#include <string>
#include <vector>

#include "appenders/LogAppender.h"

using namespace std;

class Logger
{
private:
    string name;
    vector<LogAppender*> appenders;

public:
	Logger(string name, vector<LogAppender*> appenders);
	virtual ~Logger();

    string getName() const;

    void log(LogRecord record);

};

#endif // Logger_h__
