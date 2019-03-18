#include "SignalHandler.h"

#include <iostream>

using namespace std;

SignalHandler::SignalHandler()
{

}

SignalHandler::~SignalHandler()
{
	/* Clear signals*/
	for (map<int, Signal*>::iterator it = signals.begin(); 
		it != signals.end(); 
		++it)
	{
		delete it->second;
	}

	signals.clear();
}

void SignalHandler::registerSignal(Signal* sig)
{
	signals[sig->getSignalNumber()] = sig;
}

void SignalHandler::reset(int sig_number)
{
	Signal* sig = signals.find(sig_number)->second;

	if (sig == NULL)
	{
		return;
	}

	return sig->reset();
}

int SignalHandler::signaled(int sig_number)
{
	Signal* sig = signals.find(sig_number)->second;

	if (sig == NULL)
	{
		return 0;
	}
	
	return sig->getSignaled();
}

void SignalHandler::setup()
{
	/* setup signals*/
	for (map<int, Signal*>::iterator it = signals.begin(); 
		it != signals.end(); 
		++it)
	{
		it->second->setup();
	}
}