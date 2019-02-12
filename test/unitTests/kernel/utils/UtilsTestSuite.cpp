#include "UtilsTestSuite.h"

#include "StringHelperTest.h"
#include "FileHelperTest.h"
#include "FigletHeaderTest.h"

UtilsTestSuite::UtilsTestSuite(): UnitTestSuite("Utils Test Suite", 0)
{

}

UtilsTestSuite::~UtilsTestSuite()
{

}

void UtilsTestSuite::registerTests()
{
	registerTest(new StringHelperTest);
	registerTest(new FileHelperTest);
	registerTest(new FigletHeaderTest);
}
