#ifndef IComparator_h__
#define IComparator_h__

#include <iostream>
#include <string>

using namespace std;

template<typename T>
class IComparator
{
public:
	IComparator();
	virtual ~IComparator();

	bool compare(T* item1, T* item2) = 0;

};


template <typename T>
IComparator::IComparator()
{

}

template <typename T>
IComparator::~IComparator()
{
	
}

#endif // IComparator_h__