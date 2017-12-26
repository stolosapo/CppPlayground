#ifndef ArgParserTest_h__
#define ArgParserTest_h__

#include <iostream>
#include "../../../testLib/UnitTestSuite.h"

using namespace std;

void test_arg_parser_executable_name();

class ArgParserTest: public UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	ArgParserTest();
	virtual ~ArgParserTest();
	
};

#endif // ArgParserTest_h__
