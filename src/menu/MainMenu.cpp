#include <iostream>
#include "../shared/Container.h"
#include "../log/LogServiceContainer.cpp"
#include "../euler/EulerProblemContainer.cpp"
#include "../tcpServer/TcpContainer.cpp"

using namespace std;

class MainMenu : public Container
{
public:
	MainMenu() : Container(
		1,
		"Main Menu",
		"Main Menu",
		3)
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
	}

};
