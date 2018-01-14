#ifndef Signal_h__
#define Signal_h__

#include <signal.h>

#include "../SignalHandlerFunction.h"


class Signal
{
private:
	int signalNumber;
	SignalHandlerFunction handler;

public:
	Signal(int signalNumber, SignalHandlerFunction handler);
	virtual ~Signal();

	virtual int getSignalNumber();

	virtual SignalHandlerFunction setup();
	virtual void raiseSignal();

	virtual sig_atomic_t getSignaled() = 0;
	virtual void reset() = 0;

};

#endif // Signal_h__
