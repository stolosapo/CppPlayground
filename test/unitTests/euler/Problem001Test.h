#ifndef Problem001Test_h__
#define Problem001Test_h__

#include <iostream>
#include <string>

#include "../../testLib/UnitTestSuite.h"

using namespace std;

void problem_is_solved();

class Problem001Test: public UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	Problem001Test();
	virtual ~Problem001Test();

};

#endif // Problem001Test_h__
