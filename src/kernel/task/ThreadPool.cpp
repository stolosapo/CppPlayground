#include <iostream>
#include "ThreadPool.h"

using namespace std;

ThreadPool::ThreadPool(int poolSize) : poolSize(poolSize)
{
	locker.init();
	init();
}

ThreadPool::~ThreadPool()
{
	clear();
	locker.destroy();
}

void ThreadPool::init()
{
	for (int i = 0; i < poolSize; ++i)
	{
		putBack(new Thread);
	}
}

void ThreadPool::clear()
{
	while (pool.hasNext())
	{
		delete getNext();
	}


	/* Clear used threads */
	for (map<Thread*, Thread*>::iterator it = usedThreads.begin(); 
		it != usedThreads.end(); 
		++it)
	{
		Thread* th = it->first;
		
		if (th != NULL)
		{
			th->cancel();
			delete it->first;
			th = NULL;
		}
	}

	usedThreads.clear();
}

bool ThreadPool::hasNext()
{
	return pool.hasNext();
}

bool ThreadPool::reachSize()
{
	return pool.size() >= poolSize;
}

Thread* ThreadPool::getNext()
{
	locker.lock();

	Thread* th = pool.getNext();

	if (th != NULL && th->mustDispose())
	{
		th->wait();
	}

	if (th != NULL)
	{
		usedThreads[th] = th;
	}

	locker.unlock();

	return th;
}

void ThreadPool::putBack(Thread* thread)
{
	locker.lock();

	if (!reachSize() && thread != NULL)
	{
		pool.putBack(thread);
		usedThreads.erase(thread);
	}

	locker.unlock();
}
