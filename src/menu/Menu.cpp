#include <iostream>
#include <string>
#include "Menu.h"

using namespace std;

Menu::Menu()
{
	this->exitCode = DEFAULT_EXIT_CODE;
}

Menu::~Menu()
{
	(this->menuItems).clear();
}

int Menu::getExitCode()
{
	return this->exitCode;
}

void Menu::setExitCode(int exitCode)
{
	this->exitCode = exitCode;
}

void Menu::addMenuItem(MenuItem menuItem)
{
	menuItems.push_back(menuItem);
}

vector<MenuItem> Menu::getMenuItems()
{
	return this->menuItems;
}