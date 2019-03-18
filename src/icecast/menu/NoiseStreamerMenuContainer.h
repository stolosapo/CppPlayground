#ifndef NoiseStreamerMenuContainer_h__
#define NoiseStreamerMenuContainer_h__

#include <iostream>
#include <string>
#include "../../kernel/menu/MenuContainer.h"

using namespace std;

class NoiseStreamerMenuContainer : public MenuContainer
{
public:
	NoiseStreamerMenuContainer();

	virtual ~NoiseStreamerMenuContainer();

protected:
	virtual void fillOptions();

	virtual string getHeader();

};

#endif // NoiseStreamerMenuContainer_h__
