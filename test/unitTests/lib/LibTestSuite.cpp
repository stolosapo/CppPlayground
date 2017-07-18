#include "LibTestSuite.h"

#include "functional/FunctionalTestSuite.h"

LibTestSuite::LibTestSuite(): UnitTestSuite("Lib Test Suite", 0)
{

}

LibTestSuite::~LibTestSuite()
{

}

void LibTestSuite::registerTests()
{
	registerTest(new FunctionalTestSuite);
}
