#include <iostream>

#include "MainMenuHeader.cpp"
#include "../menu/MenuContainer.h"
#include "../log/menu/LogServiceMenuContainer.h"
#include "../euler/EulerProblemContainer.cpp"
#include "../tcpServer/menu/TcpContainer.cpp"
#include "../serialization/menu/SerializationMenuContainer.h"
#include "../gpio/menu/GpioMenuContainer.h"

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
		this->addMenuItem(2, new TcpContainer);
		this->addMenuItem(3, new SerializationMenuContainer);
		this->addMenuItem(4, new GpioMenuContainer);
	}

	virtual string getHeader()
	{
		MainMenuHeader header;

		return header.getRandomHeader();
	}

};
