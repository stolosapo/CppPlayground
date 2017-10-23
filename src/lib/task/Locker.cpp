#include "Locker.h"

Locker::Locker()
{

}

Locker::~Locker()
{

}

int Locker::init()
{
        pthread_mutex_init(&_mutex, NULL);
}

int Locker::lock()
{
        return pthread_mutex_lock(&_mutex);
}

int Locker::unlock()
{
        return pthread_mutex_unlock(&_mutex);
}

int Locker::destroy()
{
        return pthread_mutex_destroy(&_mutex);
}
