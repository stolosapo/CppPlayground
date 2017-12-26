#include "MainTestSuite.h"

#include "kernel/LibTestSuite.h"
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
	registerTest(new Problem001Test);
}
