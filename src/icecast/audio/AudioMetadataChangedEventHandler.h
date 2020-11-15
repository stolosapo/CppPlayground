#ifndef AudioMetadataChangedEventHandler_h__
#define AudioMetadataChangedEventHandler_h__

#include "../NoiseStreamer.h"
#include "../../kernel/observer/EventHandler.h"

class AudioMetadataChangedEventHandler: public EventHandler
{
private:
    ILogService *logSrv;
    NoiseStreamer *noiseStreamer;

public:
	AudioMetadataChangedEventHandler(
        ILogService *logSrv,
        NoiseStreamer *noiseStreamer);
	virtual ~AudioMetadataChangedEventHandler();

    virtual void onEvent(void* sender, EventArgs* e);
};

#endif // AudioMetadataChangedEventHandler_h__
