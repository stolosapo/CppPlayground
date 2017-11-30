#ifndef ThreadPool_h__
#define ThreadPool_h__

#include <queue>

#include "Thread.h"

#include "../data_structure/SynchronizedQueue.h"

using namespace std;

class ThreadPool
{
private:
	int poolSize;

	SynchronizedQueue<Thread> pool;
	SynchronizedQueue<Thread> disposePool;

protected:
	void init();
	void clear();

public:
        ThreadPool(int poolSize);
        virtual ~ThreadPool();

        bool hasNext();
        bool reachSize();
        Thread* getNext();
        void putBack(Thread* thread);

};

#endif // ThreadPool_h__
