#ifndef TestEventHandler_h__
#define TestEventHandler_h__

#include "../../../../src/lib/observer/EventHandler.h"

class TestEventHandler : public EventHandler
{
public:
	TestEventHandler();
	virtual ~TestEventHandler();

        virtual void onEvent(void* sender, EventArgs* e);
};

#endif // TestEventHandler_h__
