#include "Signal.h"

#include <iostream>

using namespace std;

Signal::Signal(int signalNumber, SignalHandlerFunction handler) : signalNumber(signalNumber), handler(handler)
{

}

Signal::~Signal()
{

}

int Signal::getSignalNumber()
{
	return this->signalNumber;
}

SignalHandlerFunction Signal::setup()
{
	struct sigaction sig_struct;

	sig_struct.sa_handler = handler;
	sig_struct.sa_flags = 0;
	
	sigemptyset(&sig_struct.sa_mask);

	if (sigaction(signalNumber, &sig_struct, NULL) == -1)
	{
		cerr << "Problem with sigaction" << endl;
	}
}

void Signal::raiseSignal()
{
	raise(this->signalNumber);
}