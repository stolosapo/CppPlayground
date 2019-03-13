#include "TestDelegate.h"
#include "TestSender.h"

void testDelegate(void* sender, EventArgs* e)
{
	TestSender* testSender = (TestSender*) sender;

        testSender->counter++;
}