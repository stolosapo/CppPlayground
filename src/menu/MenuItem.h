#ifndef MenuItem_h__
#define MenuItem_h__

#include <iostream>
#include <string>
// #include "Menu.h"

using namespace std;

class MenuItem
{
private:
	int id;
	string name;
	string caption;
	bool enable;
	int action;
	// Menu* subMenu;

public:
	MenuItem();
	virtual ~MenuItem();
	
	int getId();
	void setId(int id);

	string getName();
	void setName(string name);

	string getCaption();
	void setCaption(string caption);

	bool getEnable();
	void setEnable(bool enable);

	// Menu *getSubMenu();
	// void setSubMenu(Menu* subMenu);
};

#endif // MenuItem_h__