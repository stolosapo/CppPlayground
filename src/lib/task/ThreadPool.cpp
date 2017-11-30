#include "ThreadPool.h"

ThreadPool::ThreadPool(int poolSize) : poolSize(poolSize)
{
	init();
}

ThreadPool::~ThreadPool()
{
	clear();
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
	pool.clear();
	disposePool.clear();
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
	return pool.getNext();
}

void ThreadPool::putBack(Thread* thread)
{
	if (!reachSize())
	{
		pool.putBack(thread);
	}
}
