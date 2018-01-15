#include <iostream>

#include "MainMenuHeader.cpp"
#include "../kernel/menu/MenuContainer.h"
#include "../log/LogServiceMenuContainer.h"
#include "../euler/EulerProblemContainer.cpp"

#include "../tcpServer/TcpMenuContainer.h"
#include "../serialization/SerializationMenuContainer.h"
#include "../gpio/GpioMenuContainer.h"
#include "../games/GameMenuContainer.h"

using namespace std;

class MainMenu : public MenuContainer
{
public:
	MainMenu() : MenuContainer(
		1,
		"Main Menu",
		"Main Menu",
		6)
	{

	}

	virtual ~MainMenu()
	{

	}

protected:
	virtual void fillOptions()
	{
		this->addMenuItem(0, new LogServiceMenuContainer);
		this->addMenuItem(1, new EulerProblemContainer);
		this->addMenuItem(2, new TcpMenuContainer);
		this->addMenuItem(3, new SerializationMenuContainer);
		this->addMenuItem(4, new GpioMenuContainer);
		this->addMenuItem(5, new IcecastMenuContainer);
		this->addMenuItem(6, new GameMenuContainer);
	}

	virtual string getHeader()
	{
		MainMenuHeader header;
		return header.getRandomHeader();
	}

};
