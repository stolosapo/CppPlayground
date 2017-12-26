#ifndef EventTest_h__
#define EventTest_h__

#include "../../../testLib/UnitTestSuite.h"


void test_event_add_event_handler__with_handler();
void test_event_add_event_handler__with_delegate();

void test_event_remove_event_handler__with_handler();
void test_event_remove_event_handler__with_delegate();

void test_event_add_event_handler__with_handler_and_operator();
void test_event_add_event_handler__with_delegate_and_operator();

void test_event_remove_event_handler__with_handler_and_operator();
void test_event_remove_event_handler__with_delegate_and_operator();


class EventTest: public UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	EventTest();
	virtual ~EventTest();

};

#endif // EventTest_h__
