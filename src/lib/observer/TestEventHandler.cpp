#include "TestEventHandler.h"

#include <iostream>

using namespace std;

TestEventHandler::TestEventHandler() : EventHandler()
{

}

TestEventHandler::~TestEventHandler()
{

}

void TestEventHandler::onEvent(void* sender, EventArgs* e)
{
        cout << "Enas Test handler" << endl;
}
