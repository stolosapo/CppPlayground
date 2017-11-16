#ifndef ThreadPool_h__
#define ThreadPool_h__

#include <stack>

#include "Thread.h"
#include "Locker.h"

using namespace std;

class ThreadPool
{
private:
	int poolSize;

	Locker locker;

	stack<Thread*> pool;

public:
        ThreadPool(int poolSize);
        virtual ~ThreadPool();

        bool hasNext();
        bool reachSize();
        Thread* getNext();
        void putBack(Thread* thread);

};

#endif // ThreadPool_h__
