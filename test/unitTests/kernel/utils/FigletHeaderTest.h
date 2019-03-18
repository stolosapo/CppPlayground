#ifndef FigletHeaderTest_h__
#define FigletHeaderTest_h__

#include <iostream>
#include "../../../testLib/UnitTestSuite.h"

using namespace std;

void test__getHeader__return_correct_result__success();
void test__getHeader__return_correct_result__when_negative_index();
void test__getHeader__return_correct_result__when_index_largen_than_size();

class FigletHeaderTest: public UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	FigletHeaderTest();
	virtual ~FigletHeaderTest();

};

#endif // FigletHeaderTest_h__
