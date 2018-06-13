#ifndef IcecastClientNavigator_h__
#define IcecastClientNavigator_h__

#include <signal.h>

#include "../kernel/log/ILogService.h"
#include "../kernel/interruption/SignalService.h"

using namespace std;

class IcecastClientNavigator
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
	IcecastClientNavigator(ILogService* logSrv, SignalService* sigSrv);
	virtual ~IcecastClientNavigator();

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

#endif // IcecastClientNavigator_h__
