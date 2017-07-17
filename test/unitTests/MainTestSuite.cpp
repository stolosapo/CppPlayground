#include "MainTestSuite.h"

#include "shared/ConvertTest.h"
#include "shared/PrimeFactorTest.h"
#include "lib/LibTest.h"
#include "arguments/ArgParserTest.h"
#include "euler/Problem001Test.h"

MainTestSuite::MainTestSuite(): UnitTestSuite("Main Test Suite", 0)
{

}

MainTestSuite::~MainTestSuite()
{

}

void MainTestSuite::registerTests()
{
	registerTest(new ConvertTest);
	registerTest(new PrimeFactorTest);
	registerTest(new LibTest);
	registerTest(new ArgParserTest);
	registerTest(new Problem001Test);
}
