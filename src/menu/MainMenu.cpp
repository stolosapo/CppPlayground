#include "MainMenu.h"

#include "../log/LogServiceMenuContainer.h"
#include "../euler/EulerProblemContainer.cpp"

#include "../tcpServer/TcpMenuContainer.h"
#include "../serialization/SerializationMenuContainer.h"
#include "../gpio/GpioMenuContainer.h"
#include "../icecast/menu/IcecastMenuContainer.h"
#include "../games/GameMenuContainer.h"

#include "../kernel/exception/domain/DomainException.h"
#include "../kernel/exception/domain/GeneralDomainErrorCode.h"


MainMenu::MainMenu(ArgumentService *argSrv)
    : MenuContainer(1, "Main Menu", "Main Menu"),
    MainMenuArgumentAdapter(argSrv)
{

}

MainMenu::~MainMenu()
{

}

void MainMenu::action()
{
    if (hasTreeArg())
    {
        tree();
        return;
    }

    if (!hasMenuItem())
    {
        MenuContainer::action();
        return;
    }

    string name = getMenuItem();
    MenuItem* foundItem = findMenuItemByName(name);

    if (foundItem == NULL)
    {
        throw DomainException(GeneralDomainErrorCode::GNR0002, name);
    }

    if (dynamic_cast<MenuContainer*>(foundItem) != NULL)
    {
        throw DomainException(GeneralDomainErrorCode::GNR0003, name);
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
