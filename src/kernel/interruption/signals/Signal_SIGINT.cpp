#include "Signal_SIGINT.h"

#include <iostream>

using namespace std;

Signal_SIGINT::Signal_SIGINT() : Signal(SIGINT, &Signal_SIGINT::signal_handler)
{
	reset();
}

Signal_SIGINT::Signal_SIGINT(SignalHandlerFunction external_handler) : Signal(SIGINT, external_handler)
{
	reset();
}

Signal_SIGINT::~Signal_SIGINT()
{
	reset();
}

sig_atomic_t Signal_SIGINT::getSignaled()
{
	return sigint_signaled;
}

void Signal_SIGINT::reset()
{
	sigint_signaled = 0;
}

void Signal_SIGINT::signal_handler(int sig)
{
	sigint_signaled = 1;

	// SIG_DFL(sig);
}