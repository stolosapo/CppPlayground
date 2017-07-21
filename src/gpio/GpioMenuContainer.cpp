#include <iostream>
#include <string>
#include "../menu/MenuContainer.h"
#include "GpioMenuItem.h"
#include "GpioMenuItemHeader.cpp"

using namespace std;

class GpioMenuContainer : public MenuContainer
{
public:
	GpioMenuContainer() : MenuContainer(
		5, 
		"Gpio",
		"Gpio",
		1)
	{
		this->setContinueQuestion(true);
	}

	virtual ~GpioMenuContainer()
	{

	}

protected:
	virtual void fillOptions()
	{
		this->addMenuItem(0, new GpioMenuItem(logSrv));
	}

	virtual string getHeader()
	{
		GpioMenuItemHeader header;
		return header.getRandomHeader();
	}

};