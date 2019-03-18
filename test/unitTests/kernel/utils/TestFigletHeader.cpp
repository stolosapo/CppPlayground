#include <iostream>
#include <string>

#include "../../../../src/kernel/utils/FigletHeader.h"

using namespace std;

class TestFigletHeader : public FigletHeader
{
public:
	TestFigletHeader() : FigletHeader()
	{

	}

	virtual ~TestFigletHeader()
	{

	}

protected:
	virtual void fillHeaders()
	{
		headers.push_back("11111");
		headers.push_back("22222");
		headers.push_back("33333");
	}

};
