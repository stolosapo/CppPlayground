#ifndef Menu_h__
#define Menu_h__

#include <iostream>
#include <vector>
#include "MenuItem.h"

using namespace std;

class Menu
{
private:
	static const int DEFAULT_EXIT_CODE = 99;

	int exitCode;
	vector<MenuItem> menuItems;

public:
	Menu();
	virtual ~Menu();

	int getExitCode();
	void setExitCode(int exitCode);

	void addMenuItem(MenuItem menuItem);
	vector<MenuItem> getMenuItems();
};

#endif // Menu_h__