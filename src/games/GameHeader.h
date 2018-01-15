#ifndef GameHeader_h__
#define GameHeader_h__

#include <iostream>
#include <string>

#include "../kernel/utils/FigletHeader.h"

using namespace std;

class GameHeader : public FigletHeader
{
public:
	GameHeader();
	virtual ~GameHeader();

private:
	string standard();

protected:
	virtual void fillHeaders();

};
#endif // GameHeader_h__