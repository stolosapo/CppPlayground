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

	queue<T> pool;

public:
    SynchronizedQueue();
    virtual ~SynchronizedQueue();

    bool hasNext();
    int size();
    T getNext();
    T front();
    const T& front() const;
    void putBack(T item);
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
    clear();
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
T SynchronizedQueue<T>::getNext()
{
	locker.lock();

	T item;

	if (hasNext())
	{
		item = pool.front();
		pool.pop();
	}

	locker.unlock();

	return item;
}

template <typename T>
T SynchronizedQueue<T>::front()
{
    return pool.front();
}

template <typename T>
const T& SynchronizedQueue<T>::front() const
{
    return pool.front();
}

template <typename T>
void SynchronizedQueue<T>::putBack(T item)
{
	locker.lock();

	pool.push(item);

	locker.unlock();
}

template <typename T>
void SynchronizedQueue<T>::clear()
{
    locker.lock();

    queue<T> empty;
    swap(pool, empty);

    locker.unlock();
}

#endif // SynchronizedQueue_h__
