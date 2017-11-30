#ifndef SynchronizedQueue_h__
#define SynchronizedQueue_h__

#include <queue>

#include "../task/Locker.h"

using namespace std;

template <typename T>
class SynchronizedQueue
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
        void clear();

};




template <typename T>
SynchronizedQueue<T>::SynchronizedQueue()
{
        locker.init();
}

template <typename T>
SynchronizedQueue<T>::~SynchronizedQueue()
{
        locker.destroy();
}

template <typename T>
bool SynchronizedQueue<T>::hasNext()
{
	return !pool.empty();
}

template <typename T>
int SynchronizedQueue<T>::size()
{
	return pool.size();
}

template <typename T>
T* SynchronizedQueue<T>::getNext()
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
void SynchronizedQueue<T>::putBack(T* item)
{
	locker.lock();

	pool.push(item);

	locker.unlock();
}

template <typename T>
void SynchronizedQueue<T>::clear()
{
        while (!pool.empty())
	{
		delete getNext();
	}
}

#endif // SynchronizedQueue_h__
