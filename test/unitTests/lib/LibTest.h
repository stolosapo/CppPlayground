#ifndef LibTest_h__
#define LibTest_h__

#include "../../testLib/UnitTestSuite.h"


class LibTest: public UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	LibTest();
	virtual ~LibTest();
	
};

#endif // LibTest_h__
