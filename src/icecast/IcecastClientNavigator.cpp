#include "IcecastClientNavigator.h"

#include <unistd.h>

IcecastClientNavigator::IcecastClientNavigator(ILogService *logSrv, SignalService* sigSrv) 
	: logSrv(logSrv), sigSrv(sigSrv)
{
	_pause = 0;
	_stop = 0;
	_next = 0;
}

IcecastClientNavigator::~IcecastClientNavigator()
{

}

void IcecastClientNavigator::pause()
{
	_pause = 1;
	logSrv->info("Playlist paused");
}

void IcecastClientNavigator::resume()
{
	_pause = 0;
	logSrv->info("Playlist resumed");
}

void IcecastClientNavigator::stop()
{
	_stop = 1;
	logSrv->info("Playlist stop playing");
}

void IcecastClientNavigator::play()
{
	_stop = 0;
	logSrv->info("Playlist start playing");
}

void IcecastClientNavigator::next()
{
	_next = 1;
	logSrv->info("Playlist go to the next track");
}

void IcecastClientNavigator::normal()
{
	_next = 0;
}

bool IcecastClientNavigator::isPaused()
{
	return _pause == 1;
}

bool IcecastClientNavigator::isStoped()
{
	return _stop == 1;
}

bool IcecastClientNavigator::isGoToNext()
{
	return _next == 1;
}

void IcecastClientNavigator::waitForResume()
{
	int ms = 500;
	int us = ms * 1000;

	while (isPaused() && !sigSrv->gotSigInt())
	{
		usleep(us);
	}
}