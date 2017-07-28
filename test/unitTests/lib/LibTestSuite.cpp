#include "LibTestSuite.h"

#include "converter/ConvertTest.h"
#include "math/PrimeFactorTest.h"
#include "functional/FunctionalTestSuite.h"

LibTestSuite::LibTestSuite(): UnitTestSuite("Lib Test Suite", 0)
{

}

LibTestSuite::~LibTestSuite()
{

}

void LibTestSuite::registerTests()
{
	registerTest(new ConvertTest);
	registerTest(new PrimeFactorTest);
	registerTest(new FunctionalTestSuite);
}
