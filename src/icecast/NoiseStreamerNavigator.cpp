#include "NoiseStreamerNavigator.h"

#include <unistd.h>

NoiseStreamerNavigator::NoiseStreamerNavigator(ILogService *logSrv, SignalService* sigSrv) 
	: logSrv(logSrv), sigSrv(sigSrv)
{
	_pause = 0;
	_stop = 0;
	_next = 0;
}

NoiseStreamerNavigator::~NoiseStreamerNavigator()
{

}

void NoiseStreamerNavigator::pause()
{
	_pause = 1;
	logSrv->info("Playlist paused");
}

void NoiseStreamerNavigator::resume()
{
	_pause = 0;
	logSrv->info("Playlist resumed");
}

void NoiseStreamerNavigator::stop()
{
	_stop = 1;
	logSrv->info("Playlist stop playing");
}

void NoiseStreamerNavigator::play()
{
	_stop = 0;
	logSrv->info("Playlist start playing");
}

void NoiseStreamerNavigator::next()
{
	_next = 1;
	logSrv->info("Playlist go to the next track");
}

void NoiseStreamerNavigator::normal()
{
	_next = 0;
}

bool NoiseStreamerNavigator::isPaused()
{
	return _pause == 1;
}

bool NoiseStreamerNavigator::isStoped()
{
	return _stop == 1;
}

bool NoiseStreamerNavigator::isGoToNext()
{
	return _next == 1;
}

void NoiseStreamerNavigator::waitForResume()
{
	int ms = 500;
	int us = ms * 1000;

	while (isPaused() && !sigSrv->gotSigInt())
	{
		usleep(us);
	}
}