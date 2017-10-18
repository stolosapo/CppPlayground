#include "AsyncTaskTest.h"
#include "TestTask.h"

#include "../../../testLib/Assertion.h"

AsyncTaskTest::AsyncTaskTest() : UnitTestSuite("AsyncTask - Test", 2)
{

}

AsyncTaskTest::~AsyncTaskTest()
{

}

void AsyncTaskTest::registerTests()
{
	registerCoveredMethod("startAsync");
	registerCoveredMethod("waitToExit");

	registerTest("Start Async with wait has correct results", &test_async_task__start_async_with_wait);
	registerTest("Start Async multiple times has correct results", &test_async_task__start_async_multiple_times);
}

void test_async_task__start_async_with_wait()
{
	TestTask task;

	task.startAsync();
	task.waitToExit();

	assertEqual(task.counter, 1);
}

void test_async_task__start_async_multiple_times()
{
	TestTask task;

	task.startAsync();
	task.waitToExit();

	task.startAsync();
	task.waitToExit();
	
	task.startAsync();
	task.waitToExit();

	assertEqual(task.counter, 3);
}