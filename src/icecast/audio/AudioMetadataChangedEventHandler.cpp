#include "AudioMetadataChangedEventHandler.h"

#include "AudioMetadataChangedEventArgs.h"
#include "../../kernel/exception/domain/DomainException.h"
#include "../../kernel/exception/ExceptionMapper.h"

AudioMetadataChangedEventHandler::AudioMetadataChangedEventHandler(
    ILogService *logSrv,
    NoiseStreamer *noiseStreamer)
    : EventHandler(),
    logSrv(logSrv),
    noiseStreamer(noiseStreamer)
{

}

AudioMetadataChangedEventHandler::~AudioMetadataChangedEventHandler()
{

}

void AudioMetadataChangedEventHandler::onEvent(void* sender, EventArgs* e)
{
    if (e == NULL)
    {
        return;
    }

    AudioMetadataChangedEventArgs* eventArgs = (AudioMetadataChangedEventArgs*) e;

    try
    {
        noiseStreamer->updateAudioMetadata(eventArgs->getMetadata());
    }
    catch(DomainException& e)
    {
        logSrv->error(handle(e));
    }
    catch(RuntimeException& e)
    {
        logSrv->error(handle(e));
    }
    catch(exception& e)
    {
        logSrv->error(e.what());
    }

    delete eventArgs;
}
