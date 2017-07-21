#include "LibTestSuite.h"

#include "functional/FunctionalTestSuite.h"
#include "math/PrimeFactorTest.h"

LibTestSuite::LibTestSuite(): UnitTestSuite("Lib Test Suite", 0)
{

}

LibTestSuite::~LibTestSuite()
{

}

void LibTestSuite::registerTests()
{
	registerTest(new PrimeFactorTest);
	registerTest(new FunctionalTestSuite);
}
