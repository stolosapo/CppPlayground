#include "Event.h"

Event::Event()
{

}

Event::~Event()
{

}

void Event::addEventHandler(EventHandler* eventHandler)
{
        eventHandlers.push_back(eventHandler);
}

void Event::removeEventHandler(EventHandler* eventHandler)
{
        int count = eventHandlers.size();
        int i;

        for (i = 0; i < count; i++)
        {
                if(eventHandlers[i] == eventHandler)
                {
                        break;
                }
        }

        if(i < count)
        {
                eventHandlers.erase(eventHandlers.begin() + i);
        }
}

void Event::raise(void* sender, EventArgs* e)
{
        int count = eventHandlers.size();

        for (int i = 0; i < count; i++)
        {
                eventHandlers[i]->onEvent(sender, e);
        }
}

Event& Event::operator+=(EventHandler* eventHandler)
{
        addEventHandler(eventHandler);
        return *this;
}

Event& Event::operator-=(EventHandler* eventHandler)
{
        removeEventHandler(eventHandler);
        return *this;
}
