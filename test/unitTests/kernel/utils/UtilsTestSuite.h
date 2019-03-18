#ifndef UtilsTestSuite_h__
#define UtilsTestSuite_h__

#include "../../../testLib/UnitTestSuite.h"


class UtilsTestSuite: public UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	UtilsTestSuite();
	virtual ~UtilsTestSuite();

};

#endif // UtilsTestSuite_h__
