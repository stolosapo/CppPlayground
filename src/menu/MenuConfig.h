#ifndef MenuConfig_h__
#define MenuConfig_h__

#include <iostream>
#include "Menu.h"
#include "MenuItem.h"

class MenuConfig
{
private:
	static MenuItem createLogMenuItem();

public:
	MenuConfig();
	~MenuConfig();
	
	static Menu* config();
};

#endif // #ifndef MenuConfig_h__