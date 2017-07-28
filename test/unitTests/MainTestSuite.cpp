#include "MainTestSuite.h"

#include "lib/LibTestSuite.h"
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
	registerTest(new LibTestSuite);
	registerTest(new ArgParserTest);
	registerTest(new Problem001Test);
}
