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
    if (hasHelpArg())
    {
        registerArguments();

        string h = MainMenuArgumentAdapter::help();
        h += MenuContainer::help();

        cout << endl << h << endl;

        return;
    }

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
	this->addMenuItem(new LogServiceMenuContainer);
	this->addMenuItem(new EulerProblemContainer);
	this->addMenuItem(new TcpMenuContainer);
	this->addMenuItem(new SerializationMenuContainer);
	this->addMenuItem(new GpioMenuContainer);
	this->addMenuItem(new IcecastMenuContainer);
	this->addMenuItem(new GameMenuContainer);
}

string MainMenu::getHeader()
{
	MainMenuHeader header;
	return header.getRandomHeader();
}
