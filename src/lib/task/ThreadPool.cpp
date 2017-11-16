#include "ThreadPool.h"

ThreadPool::ThreadPool(int poolSize)
{
	locker.init();
}

ThreadPool::~ThreadPool()
{
	locker.destroy();

	while (!pool.empty())
	{
		delete pool.top();
		pool.pop();
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