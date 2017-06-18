#include "IcecastMenuContainer.h"
#include "IcecastClientMenuItem.h"

IcecastMenuContainer::IcecastMenuContainer() : Container(
	6, 
	"Icecast",
	"Icecast",
	1)
{
	this->setContinueQuestion(true);
}

IcecastMenuContainer::~IcecastMenuContainer()
{

}

void IcecastMenuContainer::fillOptions()
{
	this->addMenuItem(0, new IcecastClientMenuItem(logSrv));
}

string IcecastMenuContainer::getHeader()
{
	return "";
}