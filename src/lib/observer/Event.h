#ifndef Event_h__
#define Event_h__

#include <iostream>
#include <vector>

#include "EventHandler.h"
#include "EventArgs.h"

using namespace std;

class Event
{
private:
        vector<EventHandler*> eventHandlers;

public:
	Event();
	virtual ~Event();

        virtual void addEventHandler(EventHandler* eventHandler);
        virtual void removeEventHandler(EventHandler* eventHandler);

        virtual void raise(void* sender, EventArgs* e);

        Event& operator+=(EventHandler* eventHandler);
        Event& operator-=(EventHandler* eventHandler);
};

#endif // Event_h__
