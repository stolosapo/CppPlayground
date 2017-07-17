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
	int level;
	vector<UnitTest*> unitTests;

protected:
	virtual void registerTests() = 0;

	void registerTest(UnitTest* test);
	void registerTest(string description, UnitTestFunction unitTestFunction);
	void ignoreTest(string description, UnitTestFunction unitTestFunction);

public:
	UnitTestSuite(string description);
	virtual ~UnitTestSuite();

	virtual void test();
	virtual bool report();

	void setLevel(int level);
	int getCount();
	int getPassedCount();
	int getIgnoredCount();

};

#endif // UnitTestSuite_h__
