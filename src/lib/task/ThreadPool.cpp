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
		th->setMustDispose(false);
	}

	locker.unlock();

	return th;
}

void ThreadPool::putBack(Thread* thread)
{
	locker.lock();

	if (!reachSize())
	{
		pool.putBack(thread);
	}

	locker.unlock();
}
