#include "MainTestSuite.h"

#include "shared/ConvertTest.h"
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
	registerTest(new ArgParserTest);
	registerTest(new Problem001Test);
}