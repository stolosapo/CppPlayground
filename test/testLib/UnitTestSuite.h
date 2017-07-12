#ifndef UnitTestSuite_h__
#define UnitTestSuite_h__

#include <iostream>
#include <string>
#include <vector>

#include "UnitTest.h"
#include "UnitTestFunction.h"

using namespace std;

class UnitTestSuite: public UnitTest
{
private:
	vector<UnitTest*> unitTests;

protected:
	virtual void registerTests() = 0;
	
	void registerTest(string description, UnitTestFunction unitTestFunction);
	int getCount();

public:
	UnitTestSuite(string description);
	virtual ~UnitTestSuite();

	virtual void test();
	virtual bool report();

};

#endif // UnitTestSuite_h__
