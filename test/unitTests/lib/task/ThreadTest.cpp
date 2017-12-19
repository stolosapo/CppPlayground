#include "ThreadTest.h"

#include "../../../../src/lib/task/Thread.h"
#include "../../../testLib/Assertion.h"

ThreadTest::ThreadTest() : UnitTestSuite("Thread - Test", 2)
{

}

ThreadTest::~ThreadTest()
{

}

void ThreadTest::registerTests()
{
	registerCoveredMethod("startAsync");
	registerCoveredMethod("waitToExit");

	registerTest("Start with wait has correct results", &test_thread__start_with_wait);
}

void* testDelegate(void* data)
{
	((int*)data)[0] = 1;
}

void test_thread__start_with_wait()
{
	int* ii = new int[1];

	Thread th;

	th += &testDelegate;
	th.start(ii);
	th.wait();

	assertEqual(ii[0], 1);
}