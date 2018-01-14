#ifndef SignalHandler_h__
#define SignalHandler_h__


#include "SignalHandlerFunction.h"


class SignalHandler
{
private:
	SignalHandlerFunction handler;

public:
	SignalHandler(SignalHandlerFunction handler);
	virtual ~SignalHandler();

};

#endif // SignalHandler_h__
