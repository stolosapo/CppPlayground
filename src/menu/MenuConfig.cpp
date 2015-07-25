#include <iostream>
#include <string>
#include "MenuConfig.h"

using namespace std;

MenuConfig::MenuConfig()
{

}

MenuConfig::~MenuConfig()
{
	
}

Menu* MenuConfig::config()
{
	Menu* menu = new Menu;

	menu->addMenuItem(createLogMenuItem());

	return menu;
}

MenuItem MenuConfig::createLogMenuItem()
{
	MenuItem item;
	
	item.setId(1);
	item.setName("Log");
	item.setTitle("Test Loging Service");
	item.setEnable(true);

	return item;
}