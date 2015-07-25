#include <iostream>
#include <string>
#include "MenuFactory.h"
#include "MenuConfig.h"
#include "../shared/convert.h"

using namespace std;

MenuFactory::MenuFactory()
{
	logSrv = LogServiceFactory::create();
}

MenuFactory::~MenuFactory()
{
	logSrv = NULL;
	menu = NULL;
}

void MenuFactory::clearScreen()
{
	logSrv->print(string(50, '\n'));
}

void MenuFactory::prompt()
{
	bool ok = true;

	logSrv->print(string(5, '\n'));
	logSrv->print("Give option: ");
	readOption();
	ok = checkOption();

	while (!ok)
	{
		promptError();
		ok = checkOption();
	}
}

void MenuFactory::promptError()
{
	logSrv->print("Give valid option: ");	
	readOption();
}

void MenuFactory::readOption()
{
	cin >> this->option;
}

bool MenuFactory::checkOption()
{
	if (this->option == menu->getExitCode())
		return true;

	vector<MenuItem> items = menu->getMenuItems();

	for (int i = 0; i < items.size(); i++)
	{
		int id = items[i].getId();
		if (id == this->option)
			return true;
	}

	return false;
}

Menu* MenuFactory::create()
{
	menu = MenuConfig::config();
	return menu;
}

void MenuFactory::print()
{
	if (menu == NULL)
	{
		menu = create();
	}

	vector<MenuItem> items = menu->getMenuItems();

	for (int i = 0; i < items.size(); i++)
	{
		string id = Convert<int>::NumberToString(items[i].getId());
		string name = items[i].getName();
		string caption = items[i].getTitle();
		bool enable = items[i].getEnable();

		if (enable)
		{
			logSrv->print(id + ")\t");
	   		logSrv->printl(caption);
	   	}
	}

	string exitCode = Convert<int>::NumberToString(menu->getExitCode());
	logSrv->printl("");
	logSrv->print(exitCode + ")\t");
	logSrv->printl("Exit");
}

void MenuFactory::run()
{
	clearScreen();
	print();
	prompt();
	
	int exitCode = menu->getExitCode();

	while (this->option != exitCode)
	{
		clearScreen();
		print();	
		prompt();
	}
}