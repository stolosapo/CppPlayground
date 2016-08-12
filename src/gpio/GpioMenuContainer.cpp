#include <iostream>
#include <string>
#include "../shared/Container.h"
#include "GpioMenuItem.h"
#include "GpioMenuItemHeader.cpp"

using namespace std;

class GpioMenuContainer : public Container
{
public:
	GpioMenuContainer() : Container(
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