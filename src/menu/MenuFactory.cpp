#include <iostream>
#include <string>
#include "MenuFactory.h"
#include "../log/LogServiceFactory.h"

using namespace std;

MenuFactory::MenuFactory()
{

}

MenuFactory::~MenuFactory()
{
	
}

Menu *MenuFactory::create()
{
	Menu* srv = new Menu;

	MenuItem item1;
	item1.setId(1);
	item1.setName("Log");
	item1.setCaption("Loging Service");
	item1.setEnable(true);

	srv->addMenuItem(item1);

	return srv;
}

void MenuFactory::print()
{
	ILogService* logSrv = LogServiceFactory::create();

	Menu* menu = create();
	vector<MenuItem> items = menu->getMenuItems();

	for (int i = 0; i < items.size(); i++)
	{
		int id = items[i].getId();
		string name = items[i].getName();
		string caption = items[i].getCaption();

   		logSrv->printl(caption);
	}
}