#ifndef IcecastMenuContainer_h__
#define IcecastMenuContainer_h__

#include <iostream>
#include <string>
#include "../../kernel/menu/MenuContainer.h"

using namespace std;

class IcecastMenuContainer : public MenuContainer
{
public:
	IcecastMenuContainer();

	virtual ~IcecastMenuContainer();

protected:
	virtual void fillOptions();

	virtual string getHeader();

};

#endif // IcecastMenuContainer_h__
