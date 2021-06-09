#include "AudioSourceControls.h"

#include <unistd.h>

AudioSourceControls::AudioSourceControls(ILogService *logSrv, SignalService* sigSrv)
    : logSrv(logSrv), sigSrv(sigSrv)
{
    _pause = 0;
    _stop = 0;
    _next = 0;
    _shutdown = 0;
}

AudioSourceControls::~AudioSourceControls()
{

}

void AudioSourceControls::pause()
{
    _pause = 1;
    logSrv->info("Playlist paused");
}

void AudioSourceControls::resume()
{
    _pause = 0;
    logSrv->info("Playlist resumed");
}

void AudioSourceControls::stop()
{
    _stop = 1;
    logSrv->info("Playlist stop playing");
}

void AudioSourceControls::play()
{
    _stop = 0;
    logSrv->info("Playlist start playing");
}

void AudioSourceControls::next()
{
    _next = 1;
    logSrv->info("Playlist go to the next track");
}

void AudioSourceControls::normal()
{
    _next = 0;
}

void AudioSourceControls::shutdown()
{
    _shutdown = 1;
    logSrv->info("Playlist is shutdown");
}

bool AudioSourceControls::isPaused()
{
    return _pause == 1;
}

bool AudioSourceControls::isStoped()
{
    return _stop == 1;
}

bool AudioSourceControls::isGoToNext()
{
    return _next == 1;
}

bool AudioSourceControls::isShutdown()
{
    return _shutdown == 1;
}

void AudioSourceControls::waitForResume()
{
    int ms = 500;
    int us = ms * 1000;

    while (isPaused() && !sigSrv->gotSigInt())
    {
        usleep(us);
    }
}

void AudioSourceControls::waitForShutdown()
{
    int ms = 500;
    int us = ms * 1000;

    logSrv->info("Playlist is waiting for shutdown");
    while (!isShutdown())
    {
        usleep(us);
    }
    logSrv->info("Playlist ended shutdown");
}
