#ifndef ErrorAppearedEventHandler_h__
#define ErrorAppearedEventHandler_h__

#include "../NoiseStreamer.h"
#include "../../kernel/observer/EventHandler.h"

class ErrorAppearedEventHandler: public EventHandler
{
private:
    NoiseStreamer *noiseStreamer;

public:
	ErrorAppearedEventHandler(
        NoiseStreamer *noiseStreamer);
	virtual ~ErrorAppearedEventHandler();

    virtual void onEvent(void* sender, EventArgs* e);
};

#endif // ErrorAppearedEventHandler_h__
