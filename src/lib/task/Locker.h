#ifndef Locker_h__
#define Locker_h__

#include <pthread.h>

class Locker
{
private:
        pthread_mutex_t _mutex;

public:
        Locker();
        virtual ~Locker();

        virtual int init();
        virtual int lock();
        virtual int unlock();
        virtual int destroy();

};

#endif // Locker_h__
