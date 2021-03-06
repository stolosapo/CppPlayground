#ifndef Signal_SIGINT_h__
#define Signal_SIGINT_h__

#include "Signal.h"


volatile static sig_atomic_t sigint_signaled;


class Signal_SIGINT : public Signal
{
private:
	static void signal_handler(int sig);

public:
	Signal_SIGINT();
	Signal_SIGINT(SignalHandlerFunction external_handler);
	virtual ~Signal_SIGINT();

	virtual sig_atomic_t getSignaled();
	virtual void reset();

};

#endif // Signal_SIGINT_h__
