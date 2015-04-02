#include <iostream>

#ifndef IJsonService_cpp__
#define IJsonService_cpp__

class IJsonService
{
public:
	virtual ~IJsonService() {}
	virtual void test() = 0;
};

#endif // IJsonService_cpp__