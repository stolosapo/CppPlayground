#include "IcecastMenuContainer.h"
#include "IcecastClientMenuItem.h"
#include "AlsaCaptureMenuItem.h"
#include "IcecastAgentMenuItem.h"
#include "IcecastAgentClientMenuItem.h"

IcecastMenuContainer::IcecastMenuContainer() : MenuContainer(
	6,
	"Icecast",
	"Icecast",
	4)
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
	this->addMenuItem(2, new IcecastAgentMenuItem(logSrv));
	this->addMenuItem(3, new IcecastAgentClientMenuItem(logSrv));
}

string IcecastMenuContainer::getHeader()
{
	return "";
}
