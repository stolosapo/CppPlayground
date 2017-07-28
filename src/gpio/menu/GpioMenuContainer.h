#ifndef GpioMenuContainer_h__
#define GpioMenuContainer_h__

#include <iostream>
#include <string>
#include "../../menu/MenuContainer.h"

using namespace std;

class GpioMenuContainer : public MenuContainer
{
public:
	GpioMenuContainer();
	virtual ~GpioMenuContainer();

protected:
	virtual void fillOptions();
	virtual string getHeader();

};
#endif // GpioMenuContainer_h__
