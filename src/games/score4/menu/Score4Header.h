#ifndef Score4Header_h__
#define Score4Header_h__

#include <iostream>
#include <string>

#include "../../../kernel/utils/FigletHeader.h"

using namespace std;

class Score4Header : public FigletHeader
{
public:
	Score4Header();
	virtual ~Score4Header();

private:
	string standard();

protected:
	virtual void fillHeaders();

};
#endif // Score4Header_h__