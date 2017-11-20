#ifndef ThreadPool_h__
#define ThreadPool_h__

#include <queue>

#include "Thread.h"
#include "Locker.h"

using namespace std;

class ThreadPool
{
private:
	int poolSize;

	Locker locker;

	queue<Thread*> pool;

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
