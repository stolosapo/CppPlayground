#include <iostream>
#include <string>
#include "MenuItem.h"

using namespace std;

MenuItem::MenuItem()
{

}

MenuItem::~MenuItem()
{
	
}

int MenuItem::getId()
{
	return this->id;
}

void MenuItem::setId(int id)
{
	this->id = id;
}

string MenuItem::getName()
{
	return this->name;
}

void MenuItem::setName(string name)
{
	this->name = name;
}

string MenuItem::getCaption()
{
	return this->caption;
}

void MenuItem::setCaption(string caption)
{
	this->caption = caption;
}

bool MenuItem::getEnable()
{
	return this->enable;
}

void MenuItem::setEnable(bool enable)
{
	this->enable = enable;
}

// Menu *MenuItem::getSubMenu()
// {
// 	return this->subMenu;
// }

// void MenuItem::setSubMenu(Menu* subMenu)
// {
// 	this->subMenu = subMenu;
// }