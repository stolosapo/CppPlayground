#include "GpioMenuContainer.h"

#include "GpioMenuItem.h"
#include "GpioMenuItemHeader.cpp"


GpioMenuContainer::GpioMenuContainer() : MenuContainer(
	5,
	"Gpio",
	"Gpio",
	1)
{
	this->setContinueQuestion(true);
}

GpioMenuContainer::~GpioMenuContainer()
{

}

void GpioMenuContainer::fillOptions()
{
	this->addMenuItem(0, new GpioMenuItem(logSrv));
}

string GpioMenuContainer::getHeader()
{
	GpioMenuItemHeader header;
	return header.getRandomHeader();
}
