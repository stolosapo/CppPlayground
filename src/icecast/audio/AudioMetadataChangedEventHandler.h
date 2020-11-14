#ifndef AudioMetadataChangedEventHandler_h__
#define AudioMetadataChangedEventHandler_h__

#include "../../kernel/observer/EventHandler.h"

class AudioMetadataChangedEventHandler: public EventHandler
{
public:
	AudioMetadataChangedEventHandler();
	virtual ~AudioMetadataChangedEventHandler();

    virtual void onEvent(void* sender, EventArgs* e);
};

#endif // AudioMetadataChangedEventHandler_h__
