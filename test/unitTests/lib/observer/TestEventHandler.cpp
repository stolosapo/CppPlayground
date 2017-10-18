#include "TestEventHandler.h"

#include <iostream>

#include "TestSender.h"

using namespace std;

TestEventHandler::TestEventHandler() : EventHandler()
{

}

TestEventHandler::~TestEventHandler()
{

}

void TestEventHandler::onEvent(void* sender, EventArgs* e)
{
        TestSender* testSender = (TestSender*) sender;

        testSender->counter++;
}