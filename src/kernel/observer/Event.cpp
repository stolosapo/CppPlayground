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

void Event::addEventHandler(Delegate delegate)
{
        delegates.push_back(delegate);
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

void Event::removeEventHandler(Delegate delegate)
{
        int count = delegates.size();
        int i;

        for (i = 0; i < count; i++)
        {
                if(delegates[i] == delegate)
                {
                        break;
                }
        }

        if(i < count)
        {
                delegates.erase(delegates.begin() + i);
        }
}

void Event::raise(void* sender, EventArgs* e)
{
        /* Iterate Event Handlers */
        for (int i = 0; i < eventHandlers.size(); i++)
        {
                eventHandlers[i]->onEvent(sender, e);
        }

        /* Iterate delegates */
        for (int i = 0; i < delegates.size(); i++)
        {
                (delegates[i])(sender, e);
        }
}

Event& Event::operator+=(EventHandler* eventHandler)
{
        addEventHandler(eventHandler);
        return *this;
}

Event& Event::operator+=(Delegate delegate)
{
        addEventHandler(delegate);
        return *this;
}

Event& Event::operator-=(EventHandler* eventHandler)
{
        removeEventHandler(eventHandler);
        return *this;
}

Event& Event::operator-=(Delegate delegate)
{
        removeEventHandler(delegate);
        return *this;
}