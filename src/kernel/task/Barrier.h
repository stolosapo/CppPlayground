#ifndef Barrier_h__
#define Barrier_h__

#include <pthread.h>

class Barrier
{
private:
        pthread_barrier_t _barrier;

        int number;

public:
        Barrier(int number);
        virtual ~Barrier();

        virtual int init();
        virtual int wait();
        virtual int destroy();

};

#endif // Barrier_h__
