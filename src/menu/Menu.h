#ifndef Menu_h__
#define Menu_h__

#include <iostream>
#include <vector>
#include "MenuItem.h"

using namespace std;

class Menu
{
private:
	vector<MenuItem> menuItems;

public:
	Menu();
	virtual ~Menu();

	void addMenuItem(MenuItem menuItem);
	vector<MenuItem> getMenuItems();
};

#endif // Menu_h__