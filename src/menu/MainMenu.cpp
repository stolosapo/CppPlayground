#include <iostream>
#include "../shared/Container.h"
#include "../euler/EulerProblemContainer.h"

using namespace std;

class MainMenu : public Container
{
private:

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
	virtual void execute(int menuItemId)
	{

	}

	virtual void fillOptions()
	{
		this->addMenuItem(0, new EulerProblemContainer);
	}

};