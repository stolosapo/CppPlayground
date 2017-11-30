#ifndef SynchronizedQueue_h__
#define SynchronizedQueue_h__

#include <queue>

#include "../task/Locker.h"

using namespace std;

template <typename T>
class SynchronizedQueue<T>
{
private:
        Locker locker;

	queue<T*> pool;

public:
        SynchronizedQueue();
        virtual ~SynchronizedQueue();

        bool hasNext();
        int size();
        T* getNext();
        void putBack(T* item);

};




template <typename T>
SynchronizedQueue::SynchronizedQueue()
{
        locker.init();
}

template <typename T>
SynchronizedQueue::~SynchronizedQueue()
{
        locker.destroy();
}

template <typename T>
bool SynchronizedQueue::hasNext()
{
	return !pool.empty();
}

template <typename T>
int SynchronizedQueue::size()
{
	return pool.size();
}

template <typename T>
T* SynchronizedQueue::getNext()
{
	locker.lock();

	T* item;

	if (hasNext())
	{
		item = pool.front();
		pool.pop();
	}
	else
	{
		item = NULL;
	}


	locker.unlock();

	return item;
}

template <typename T>
void SynchronizedQueue::putBack(T* item)
{
	locker.lock();

	pool.push(item);

	locker.unlock();
}

#endif // SynchronizedQueue_h__
