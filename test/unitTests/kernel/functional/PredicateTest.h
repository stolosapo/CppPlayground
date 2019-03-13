#ifndef PredicateTest_h__
#define PredicateTest_h__

#include "../../../testLib/UnitTestSuite.h"


void test_predicate_with_int_apply();
void test_predicate_with_pointer_apply();


class PredicateTest: public UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	PredicateTest();
	virtual ~PredicateTest();
	
};

#endif // PredicateTest_h__
