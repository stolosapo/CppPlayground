#ifndef Event_h__
#define Event_h__

#include <iostream>
#include <string>
#include <map>

using namespace std;

template<typename T>
class Event
{
private:

	/* Delegate to Factory Method */
	typedef T* (T::*factoryMethod)();

	factoryMethod factory;
	

protected:
	


public:
	Event();
	virtual ~Event();

	void addFactoryMethodHandler(factoryMethod method);

	T* invokeFactoryMethod(T &object);

};


/********************************************
*
*			IMPLEMENTATION
*
*********************************************/

template<typename T>
Event<T>::Event()
{

}


template<typename T>
Event<T>::~Event()
{
	
}


template<typename T>
void Event<T>::addFactoryMethodHandler(factoryMethod method)
{
	factory = method;
}


template<typename T>
T* Event<T>::invokeFactoryMethod(T &object)
{
	if (factory == NULL)
	{
		return NULL;
	}

	return (object.*factory)();
}

#endif // Event_h__