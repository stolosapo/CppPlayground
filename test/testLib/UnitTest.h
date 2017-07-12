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
	UnitTestFunction testFunction;

protected:
	bool passed;

public:
	UnitTest(string description);
	UnitTest(string description, UnitTestFunction testFunction);
	virtual ~UnitTest();

	virtual void test();
	virtual bool report();

	string getDescription();
	bool isPassed();
	
};

#endif // UnitTest_h__
