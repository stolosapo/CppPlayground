#include "IcecastMenuContainer.h"
#include "IcecastClientMenuItem.h"
#include "AlsaCaptureMenuItem.h"

IcecastMenuContainer::IcecastMenuContainer() : MenuContainer(
	6,
	"Icecast",
	"Icecast",
	2)
{
	this->setContinueQuestion(true);
}

IcecastMenuContainer::~IcecastMenuContainer()
{

}

void IcecastMenuContainer::fillOptions()
{
	this->addMenuItem(0, new IcecastClientMenuItem(logSrv));
	this->addMenuItem(1, new AlsaCaptureMenuItem(logSrv));
}

string IcecastMenuContainer::getHeader()
{
	return "";
}
