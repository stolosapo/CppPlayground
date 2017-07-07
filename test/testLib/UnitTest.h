#ifndef UnitTest_h__
#define UnitTest_h__

#include <iostream>
#include <string>

#include "UnitTestFunction.h"

using namespace std;

class UnitTest
{
private:
	string description;
	string cause;
	bool passed;
	UnitTestFunction testFunction;

public:
	UnitTest(string description, UnitTestFunction testFunction);
	virtual ~UnitTest();

	void test();
	bool report();
	
};

#endif // UnitTest_h__
