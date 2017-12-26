#ifndef SerializationMenuContainer_h__
#define SerializationMenuContainer_h__

#include <iostream>
#include <string>

#include "../../kernel/menu/MenuContainer.h"

using namespace std;

class SerializationMenuContainer : public MenuContainer
{
public:
	SerializationMenuContainer();
	virtual ~SerializationMenuContainer();

protected:
	virtual void fillOptions();
	virtual string getHeader();

};
#endif // SerializationMenuContainer_h__
