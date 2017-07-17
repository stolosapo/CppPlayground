#include "LibTest.h"

#include "functional/FunctionalTest.h"

LibTest::LibTest(): UnitTestSuite("Lib Test Suite", 0)
{

}

LibTest::~LibTest()
{

}

void LibTest::registerTests()
{
	registerTest(new FunctionalTest);
}
