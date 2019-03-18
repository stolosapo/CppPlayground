#ifndef MainMenu_h__
#define MainMenu_h__

#include <iostream>

#include "MainMenuHeader.cpp"
#include "MainMenuArgumentAdapter.h"
#include "../kernel/menu/MenuContainer.h"

class MainMenu : public MenuContainer, public MainMenuArgumentAdapter
{
public:
	MainMenu(ArgumentService *argSrv);
	virtual ~MainMenu();

    virtual void action();

protected:
	virtual void fillOptions();
	virtual string getHeader();

};

#endif // MainMenu_h__
