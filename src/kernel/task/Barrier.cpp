#include "Barrier.h"

Barrier::Barrier(int number) : number(number)
{

}

Barrier::~Barrier()
{

}

int Barrier::init()
{
        return pthread_barrier_init(&_barrier, 0, number);
}

int Barrier::wait()
{
        return pthread_barrier_wait(&_barrier);
}

int Barrier::destroy()
{
        return pthread_barrier_destroy(&_barrier);
}
