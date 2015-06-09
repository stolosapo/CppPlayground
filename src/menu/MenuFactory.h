#ifndef MenuFactory_h__
#define MenuFactory_h__

#include <iostream>
#include "Menu.h"
#include "../log/LogServiceFactory.h"

class MenuFactory
{
private:
	ILogService* logSrv;
	Menu* menu;
	int option;

	void clearScreen();
	void prompt();
	void promptError();
	void readOption();
	bool checkOption();

public:
	MenuFactory();
	~MenuFactory();
	
	Menu* create();
	void print();
	void run();
};

#endif // #ifndef MenuFactory_h__