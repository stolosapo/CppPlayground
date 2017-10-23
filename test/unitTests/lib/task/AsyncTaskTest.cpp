#include "AsyncTaskTest.h"
#include "TestTask.h"
#include "TestSharedTask.h"

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
	registerTest("Start Async multiple times with shared data", &test_async_task__with_shared_data);
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

void test_async_task__with_shared_data()
{
	int shared = 0;

	TestSharedTask task1(&shared);
	TestSharedTask task2(&shared);
	TestSharedTask task3(&shared);
	TestSharedTask task4(&shared);

	task1.startAsync();
	task2.startAsync();
	task3.startAsync();
	task4.startAsync();

	task1.waitToExit();
	task2.waitToExit();
	task3.waitToExit();
	task4.waitToExit();

	assertEqual(shared, 4);
}
