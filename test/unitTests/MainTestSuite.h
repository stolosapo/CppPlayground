#ifndef MainTestSuite_h__
#define MainTestSuite_h__

#include "../testLib/UnitTestSuite.h"

class MainTestSuite: public UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	MainTestSuite();
	virtual ~MainTestSuite();
	
};

#endif // MainTestSuite_h__
