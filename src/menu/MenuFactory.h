#ifndef MenuFactory_h__
#define MenuFactory_h__

#include <iostream>
#include "Menu.h"

class MenuFactory
{
public:
	MenuFactory();
	~MenuFactory();
	
	static Menu *create();
	static void print();
};

#endif // #ifndef MenuFactory_h__