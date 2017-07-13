#include "MainTestSuite.h"

#include "shared/ConvertTest.h"
#include "shared/PrimeFactorTest.h"
#include "arguments/ArgParserTest.h"
#include "euler/Problem001Test.h"

MainTestSuite::MainTestSuite(): UnitTestSuite("Main Test Suite")
{

}

MainTestSuite::~MainTestSuite()
{

}

void MainTestSuite::registerTests()
{
	registerTest(new ConvertTest);
	registerTest(new PrimeFactorTest);
	registerTest(new ArgParserTest);
	registerTest(new Problem001Test);
}
