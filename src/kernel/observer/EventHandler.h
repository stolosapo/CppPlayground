#ifndef EventHandler_h__
#define EventHandler_h__

#include "EventClass.h"
#include "EventArgs.h"

class EventHandler
{
public:
	EventHandler();
	virtual ~EventHandler();

        virtual void onEvent(void* sender, EventArgs* e) = 0;
};

#endif // EventHandler_h__
