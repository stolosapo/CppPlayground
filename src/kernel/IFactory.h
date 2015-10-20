#ifndef IFACTORY_H__
#define IFACTORY_H__

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class IFactory 
{
public:	
	IFactory();
	virtual ~IFactory();

	virtual static T* create() = 0;
};

#endif /* IFACTORY_H__ */