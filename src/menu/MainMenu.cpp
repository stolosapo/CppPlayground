#include <iostream>
#include "../shared/Container.h"
#include "../euler/EulerProblemContainer.cpp"

using namespace std;

class MainMenu : public Container
{
public:
	MainMenu() : Container(
		1,
		"Main Menu",
		"Main Menu",
		1)
	{

	}

	virtual ~MainMenu()
	{

	}

protected:
	virtual void fillOptions()
	{
		this->addMenuItem(0, new EulerProblemContainer);
	}

};
