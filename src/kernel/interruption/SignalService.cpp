#include "SignalService.h"

#include "signals/Signal_SIGINT.h"

SignalService::SignalService() : SignalHandler(), IService()
{

}

SignalService::~SignalService()
{

}

void SignalService::registerSignals()
{
	registerSignal(new Signal_SIGINT);
}

bool SignalService::gotSigInt()
{
	return signaled(SIGINT);
}

bool SignalService::gotSigIntAndReset()
{
	bool got = gotSigInt();

	if (got)
	{
		reset(SIGINT);
	}


	return got;
}
