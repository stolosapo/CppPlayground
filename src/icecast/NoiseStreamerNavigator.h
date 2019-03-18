#ifndef NoiseStreamerNavigator_h__
#define NoiseStreamerNavigator_h__

#include <signal.h>

#include "../kernel/log/ILogService.h"
#include "../kernel/interruption/SignalService.h"

using namespace std;

class NoiseStreamerNavigator
{
private:
	volatile sig_atomic_t _pause;
	volatile sig_atomic_t _stop;
	volatile sig_atomic_t _next;

	ILogService *logSrv;
	SignalService* sigSrv;

protected:
	void waitForResume();

public:
	NoiseStreamerNavigator(ILogService* logSrv, SignalService* sigSrv);
	virtual ~NoiseStreamerNavigator();

	void pause();
	void resume();
	void stop();
	void play();
	void next();
	void normal();

	bool isPaused();
	bool isStoped();
	bool isGoToNext();

};

#endif // NoiseStreamerNavigator_h__
