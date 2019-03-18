#ifndef SignalHandler_h__
#define SignalHandler_h__

#include <map>

#include "signals/Signal.h"

using namespace std;

class SignalHandler
{
private:
	map<int, Signal*> signals;

protected:
	void registerSignal(Signal* sig);
	
public:
	SignalHandler();
	virtual ~SignalHandler();

	void setup();
	void reset(int sig);
	int signaled(int sig);

	virtual void registerSignals() = 0;

};

#endif // SignalHandler_h__
