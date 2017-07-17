#ifndef FunctionalTest_h__
#define FunctionalTest_h__

#include "../../../testLib/UnitTestSuite.h"


class FunctionalTest: public UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	FunctionalTest();
	virtual ~FunctionalTest();
	
};

#endif // FunctionalTest_h__
