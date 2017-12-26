#ifndef Queue_h__
#define Queue_h__

#include <queue>

using namespace std;

template <typename T>
class Queue
{
private:
	queue<T*> pool;

public:
        Queue();
        virtual ~Queue();

        bool hasNext();
        int size();
        T* getNext();
        void putBack(T* item);
        void clear();

};




template <typename T>
Queue<T>::Queue()
{

}

template <typename T>
Queue<T>::~Queue()
{

}

template <typename T>
bool Queue<T>::hasNext()
{
	return !pool.empty();
}

template <typename T>
int Queue<T>::size()
{
	return pool.size();
}

template <typename T>
T* Queue<T>::getNext()
{
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

	return item;
}

template <typename T>
void Queue<T>::putBack(T* item)
{
	pool.push(item);
}

template <typename T>
void Queue<T>::clear()
{
        while (!pool.empty())
	{
		delete getNext();
	}
}

#endif // Queue_h__
