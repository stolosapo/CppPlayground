#ifndef FunctionalTestSuite_h__
#define FunctionalTestSuite_h__

#include "../../../testLib/UnitTestSuite.h"


class FunctionalTestSuite: public UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	FunctionalTestSuite();
	virtual ~FunctionalTestSuite();

};

#endif // FunctionalTestSuite_h__
