#include "ThreadPool.h"

ThreadPool::ThreadPool(int poolSize)
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
	while (!pool.empty())
	{
		delete getNext();
	}
}

bool ThreadPool::hasNext()
{
	return !pool.empty();
}

bool ThreadPool::reachSize()
{
	return pool.size() >= poolSize;
}

Thread* ThreadPool::getNext()
{
	locker.lock();

	Thread* th;

	if (hasNext())
	{
		th = pool.top();
		pool.pop();
	}
	else
	{
		th = NULL;
	}


	locker.unlock();

	return th;
}

void ThreadPool::putBack(Thread* thread)
{
	locker.lock();

	if (!reachSize())
	{
		pool.push(thread);
	}

	locker.unlock();
}