#include "MainMenu.h"

#include "../log/LogServiceMenuContainer.h"
#include "../euler/EulerProblemContainer.cpp"

#include "../tcpServer/TcpMenuContainer.h"
#include "../serialization/SerializationMenuContainer.h"
#include "../gpio/GpioMenuContainer.h"
#include "../icecast/menu/IcecastMenuContainer.h"
#include "../games/GameMenuContainer.h"

MainMenu::MainMenu(ArgumentService *argSrv)
    : MenuContainer(1, "Main Menu", "Main Menu", 7),
    MainMenuArgumentAdapter(argSrv)
{

}

MainMenu::~MainMenu()
{

}

void MainMenu::action()
{
    if (!hasMenuItem())
    {
        MenuContainer::action();
        return;
    }

    string name = getMenuItem();
    MenuItem* foundItem = findMenuItemByName(name);

    if (foundItem == NULL)
    {
        cerr << "Not found menu item with name: " << name << endl;
        return;
    }

    if (((MenuContainer*) foundItem) != NULL)
    {
        cerr << "Menu Item must not be MenuContainer" << endl;
        return;
    }

    foundItem->action();
}

void MainMenu::fillOptions()
{
	this->addMenuItem(0, new LogServiceMenuContainer);
	this->addMenuItem(1, new EulerProblemContainer);
	this->addMenuItem(2, new TcpMenuContainer);
	this->addMenuItem(3, new SerializationMenuContainer);
	this->addMenuItem(4, new GpioMenuContainer);
	this->addMenuItem(5, new IcecastMenuContainer);
	this->addMenuItem(6, new GameMenuContainer);
}

string MainMenu::getHeader()
{
	MainMenuHeader header;
	return header.getRandomHeader();
}
