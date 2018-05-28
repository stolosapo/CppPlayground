#ifndef ThreadPool_h__
#define ThreadPool_h__

#include <queue>
#include <map>

#include "Thread.h"
#include "Locker.h"

#include "../data_structure/Queue.h"

using namespace std;

class ThreadPool
{
private:
	int poolSize;

	Locker locker;

	Queue<Thread> pool;
	map<Thread*, Thread*> usedThreads;


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

	int numberOfActiveThreads();

};

#endif // ThreadPool_h__
