#include "EventTest.h"

#include "../../../testLib/Assertion.h"

#include "TestSender.h"
#include "TestEventHandler.h"
#include "TestDelegate.h"

#include "../../../../src/kernel/observer/Event.h"
#include "../../../../src/kernel/observer/EventArgs.h"

EventTest::EventTest() : UnitTestSuite("Event - Test", 9)
{

}

EventTest::~EventTest()
{

}

void EventTest::registerTests()
{
	registerCoveredMethod("addEventHandler(EventHandler*)");
	registerCoveredMethod("addEventHandler(Delegate)");

	registerCoveredMethod("removeEventHandler(EventHandler*)");
	registerCoveredMethod("removeEventHandler(Delegate)");

	registerCoveredMethod("+= EventHandler*");
	registerCoveredMethod("+= Delegate");

	registerCoveredMethod("-= EventHandler*");
	registerCoveredMethod("-= Delegate");

	registerCoveredMethod("raise");

	registerTest("Add Event Handler passing EventHandler", &test_event_add_event_handler__with_handler);
	registerTest("Add Event Handler passing Delegate", &test_event_add_event_handler__with_delegate);

	registerTest("Remove Event Handler passing EventHandler", &test_event_remove_event_handler__with_handler);
	registerTest("Remove Event Handler passing Delegate", &test_event_remove_event_handler__with_delegate);

	registerTest("Add Event Handler using += passing EventHandler", &test_event_add_event_handler__with_handler_and_operator);
	registerTest("Add Event Handler using += passing Delegate", &test_event_add_event_handler__with_delegate_and_operator);
	
	registerTest("Remove Event Handler using -= passing EventHandler", &test_event_remove_event_handler__with_handler_and_operator);
	registerTest("Remove Event Handler using -= passing Delegate", &test_event_remove_event_handler__with_delegate_and_operator);
}


void test_event_add_event_handler__with_handler()
{
	TestSender* sender = new TestSender;

	Event event;

	event.addEventHandler(new TestEventHandler);
	event.addEventHandler(new TestEventHandler);

	event.raise(sender, new EventArgs);

	assertEqual(sender->counter, 2);
}

void test_event_add_event_handler__with_delegate()
{
	TestSender* sender = new TestSender;

	Event event;

	event.addEventHandler(&testDelegate);
	event.addEventHandler(&testDelegate);

	event.raise(sender, new EventArgs);

	assertEqual(sender->counter, 2);
}

void test_event_remove_event_handler__with_handler()
{
	TestSender* sender = new TestSender;

	TestEventHandler* h1 = new TestEventHandler;
	TestEventHandler* h2 = new TestEventHandler;

	Event event;

	event.addEventHandler(h1);
	event.addEventHandler(h2);

	event.removeEventHandler(h1);
	event.removeEventHandler(h2);

	event.raise(sender, new EventArgs);

	assertEqual(sender->counter, 0);
}

void test_event_remove_event_handler__with_delegate()
{
	TestSender* sender = new TestSender;

	Event::Delegate d1 = &testDelegate;
	Event::Delegate d2 = &testDelegate;

	Event event;

	event.addEventHandler(d1);
	event.addEventHandler(d2);

	event.removeEventHandler(d1);
	event.removeEventHandler(d2);

	event.raise(sender, new EventArgs);

	assertEqual(sender->counter, 0);
}

void test_event_add_event_handler__with_handler_and_operator()
{
	TestSender* sender = new TestSender;

	Event event;

	event += new TestEventHandler;
	event += new TestEventHandler;

	event.raise(sender, new EventArgs);

	assertEqual(sender->counter, 2);
}

void test_event_add_event_handler__with_delegate_and_operator()
{
	TestSender* sender = new TestSender;

	Event event;

	event += &testDelegate;
	event += &testDelegate;

	event.raise(sender, new EventArgs);

	assertEqual(sender->counter, 2);
}

void test_event_remove_event_handler__with_handler_and_operator()
{
	TestSender* sender = new TestSender;

	TestEventHandler* h1 = new TestEventHandler;
	TestEventHandler* h2 = new TestEventHandler;

	Event event;

	event += h1;
	event += h2;

	event -= h1;
	event -= h2;

	event.raise(sender, new EventArgs);

	assertEqual(sender->counter, 0);
}

void test_event_remove_event_handler__with_delegate_and_operator()
{
	TestSender* sender = new TestSender;

	Event::Delegate d1 = &testDelegate;
	Event::Delegate d2 = &testDelegate;

	Event event;

	event += d1;
	event += d2;

	event -= d1;
	event -= d2;

	event.raise(sender, new EventArgs);

	assertEqual(sender->counter, 0);
}