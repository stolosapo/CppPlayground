#ifndef Event_h__
#define Event_h__

#include <iostream>
#include <vector>

#include "EventHandler.h"
#include "EventArgs.h"

using namespace std;

class Event
{
public:
	typedef void (*Delegate)(void* sender, EventArgs* e);

	Event();
	virtual ~Event();

        virtual void addEventHandler(EventHandler* eventHandler);
        virtual void addEventHandler(Delegate delegate);

        virtual void removeEventHandler(EventHandler* eventHandler);
        virtual void removeEventHandler(Delegate delegate);

        virtual void raise(void* sender, EventArgs* e);

        Event& operator+=(EventHandler* eventHandler);
        Event& operator+=(Delegate delegate);

        Event& operator-=(EventHandler* eventHandler);
        Event& operator-=(Delegate delegate);

private:
        vector<EventHandler*> eventHandlers;
        vector<Delegate> delegates;
        
};

#endif // Event_h__
