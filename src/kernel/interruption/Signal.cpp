#include "Signal.h"

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
	return signal(signalNumber, handler);
}

void Signal::raiseSignal()
{
	raise(this->signalNumber);
}