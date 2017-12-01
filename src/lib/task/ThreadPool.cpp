#include "ThreadPool.h"

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
	pool.clear();
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
