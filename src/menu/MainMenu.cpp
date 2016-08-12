#include <iostream>

#include "MainMenuHeader.cpp"
#include "../shared/Container.h"
#include "../log/LogServiceContainer.cpp"
#include "../euler/EulerProblemContainer.cpp"
#include "../tcpServer/TcpContainer.cpp"
#include "../serialization/SerializationContainer.cpp"
#include "../gpio/GpioMenuContainer.cpp"

using namespace std;

class MainMenu : public Container
{
public:
	MainMenu() : Container(
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
		this->addMenuItem(0, new LogServiceContainer);
		this->addMenuItem(1, new EulerProblemContainer);
		this->addMenuItem(2, new TcpContainer);
		this->addMenuItem(3, new SerializationContainer);
		this->addMenuItem(4, new GpioMenuContainer);
	}

	virtual string getHeader()
	{
		MainMenuHeader header;

		return header.getRandomHeader();
	}

};
