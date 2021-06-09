#ifndef AudioSourceControls_h__
#define AudioSourceControls_h__

#include <signal.h>

#include "../../kernel/log/ILogService.h"
#include "../../kernel/interruption/SignalService.h"

using namespace std;

class AudioSourceControls
{
private:
	volatile sig_atomic_t _pause;
	volatile sig_atomic_t _stop;
	volatile sig_atomic_t _next;
	volatile sig_atomic_t _shutdown;

	ILogService *logSrv;
	SignalService* sigSrv;

protected:
    void shutdown();
    bool isShutdown();
	void waitForResume();
	void waitForShutdown();

public:
	AudioSourceControls(ILogService* logSrv, SignalService* sigSrv);
	virtual ~AudioSourceControls();

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

#endif // AudioSourceControls_h__
