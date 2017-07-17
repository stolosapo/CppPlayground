#include "FunctionalTest.h"

#include "PredicateTest.h"
#include "FunctionTest.h"


FunctionalTest::FunctionalTest(): UnitTestSuite("Functional Test Suite", 0)
{

}

FunctionalTest::~FunctionalTest()
{

}

void FunctionalTest::registerTests()
{
	registerTest(new PredicateTest);
	registerTest(new FunctionTest);
}
