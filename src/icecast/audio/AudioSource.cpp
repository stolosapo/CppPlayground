#include "AudioSource.h"

AudioSource::AudioSource(
    ILogService* logSrv,
    SignalService* sigSrv,
    const AudioSourceType type)
    : logSrv(logSrv),
    sigSrv(sigSrv),
    type(type),
    AudioSourceControls(logSrv, sigSrv)
{
    OnError = Event();
    OnAudioMetadataChanged = Event();
}

AudioSource::~AudioSource()
{

}

AudioSourceType AudioSource::getType() const
{
    return type;
}

void AudioSource::shutdownAudioSource()
{
    if (!isStoped())
    {
        stop();
    }

    if (!isShutdown())
    {
        shutdown();
        waitForShutdown();
    }
}
