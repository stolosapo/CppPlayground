#include <iostream>

#include "MainMenuHeader.cpp"
#include "../kernel/menu/MenuContainer.h"
#include "../log/LogServiceMenuContainer.h"
#include "../euler/EulerProblemContainer.cpp"
#include "../tcpServer/TcpMenuContainer.h"
#include "../serialization/SerializationMenuContainer.h"
#include "../gpio/GpioMenuContainer.h"

using namespace std;

class MainMenu : public MenuContainer
{
public:
	MainMenu() : MenuContainer(
		1,
		"Main Menu",
		"Main Menu",
		5)
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
	}

	virtual string getHeader()
	{
		MainMenuHeader header;

		return header.getRandomHeader();
	}

};
