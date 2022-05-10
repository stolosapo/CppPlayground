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
	volatile sig_atomic_t _shutdown;

	ILogService *logSrv;
	SignalService* sigSrv;

protected:
	void waitForResume();
	void waitForShutdown();

public:
	NoiseStreamerNavigator(ILogService* logSrv, SignalService* sigSrv);
	virtual ~NoiseStreamerNavigator();

	void pause();
	void resume();
	void stop();
	void play();
	void next();
	void normal();
    void shutdown();

	bool isPaused();
	bool isStoped();
	bool isGoToNext();
    bool isShutdown();

};

#endif // NoiseStreamerNavigator_h__
