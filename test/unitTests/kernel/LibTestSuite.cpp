#include "LibTestSuite.h"

#include "arguments/ArgParserTest.h"
#include "converter/ConvertTest.h"
#include "math/PrimeFactorTest.h"
#include "functional/FunctionalTestSuite.h"
#include "observer/EventTest.h"
#include "task/AsyncTaskTest.h"
#include "task/ThreadTest.h"
#include "task/ThreadPoolTest.h"
#include "utils/UtilsTestSuite.h"

LibTestSuite::LibTestSuite(): UnitTestSuite("Lib Test Suite", 0)
{

}

LibTestSuite::~LibTestSuite()
{

}

void LibTestSuite::registerTests()
{
	registerTest(new ArgParserTest);
	registerTest(new ConvertTest);
	registerTest(new PrimeFactorTest);
	registerTest(new FunctionalTestSuite);
	registerTest(new EventTest);
	registerTest(new AsyncTaskTest);
	registerTest(new ThreadTest);
	registerTest(new UtilsTestSuite);
}