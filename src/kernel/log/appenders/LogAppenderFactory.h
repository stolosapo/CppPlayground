#ifndef LogAppenderFactory_h__
#define LogAppenderFactory_h__

#include "LogAppender.h"
#include "../config/LogAppenderConfig.h"

class LogAppenderFactory
{
public:
	LogAppenderFactory();
	virtual ~LogAppenderFactory();

	LogAppender *createFromConfig(LogAppenderConfig *config);
};

#endif // #ifndef LogAppenderFactory_h__
