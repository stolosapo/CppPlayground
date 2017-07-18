#include "FunctionalTestSuite.h"

#include "PredicateTest.h"
#include "FunctionTest.h"


FunctionalTestSuite::FunctionalTestSuite(): UnitTestSuite("Functional Test Suite", 0)
{

}

FunctionalTestSuite::~FunctionalTestSuite()
{

}

void FunctionalTestSuite::registerTests()
{
	registerTest(new PredicateTest);
	registerTest(new FunctionTest);
}
