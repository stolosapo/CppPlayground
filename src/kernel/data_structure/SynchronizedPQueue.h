#ifndef SynchronizedPQueue_h__
#define SynchronizedPQueue_h__

#include <queue>

#include "../task/Locker.h"

using namespace std;

template <typename T>
class SynchronizedPQueue
{
private:
    Locker locker;

	queue<T*> pool;

public:
    SynchronizedPQueue();
    virtual ~SynchronizedPQueue();

    bool hasNext();
    int size();
    T* getNext();
    T* front();
    const T& front() const;
    void putBack(T* item);
    void clear();

};




template <typename T>
SynchronizedPQueue<T>::SynchronizedPQueue()
{
    locker.init();
}

template <typename T>
SynchronizedPQueue<T>::~SynchronizedPQueue()
{
    clear();
    locker.destroy();
}

template <typename T>
bool SynchronizedPQueue<T>::hasNext()
{
	return !pool.empty();
}

template <typename T>
int SynchronizedPQueue<T>::size()
{
	return pool.size();
}

template <typename T>
T* SynchronizedPQueue<T>::getNext()
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
T* SynchronizedPQueue<T>::front()
{
    return pool.front();
}

template <typename T>
const T& SynchronizedPQueue<T>::front() const
{
    return pool.front();
}

template <typename T>
void SynchronizedPQueue<T>::putBack(T* item)
{
	locker.lock();

	pool.push(item);

	locker.unlock();
}

template <typename T>
void SynchronizedPQueue<T>::clear()
{
    while (!pool.empty())
    {
        delete getNext();
    }
}

#endif // SynchronizedPQueue_h__
