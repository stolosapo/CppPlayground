#ifndef LibTestSuite_h__
#define LibTestSuite_h__

#include "../../testLib/UnitTestSuite.h"


class LibTestSuite: public UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	LibTestSuite();
	virtual ~LibTestSuite();

};

#endif // LibTestSuite_h__
