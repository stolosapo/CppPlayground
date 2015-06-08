#include <iostream>
#include <string>
#include "Menu.h"

using namespace std;

Menu::Menu()
{

}

Menu::~Menu()
{
	(this->menuItems).clear();
}

void Menu::addMenuItem(MenuItem menuItem)
{
	menuItems.push_back(menuItem);
}

vector<MenuItem> Menu::getMenuItems()
{
	return this->menuItems;
}