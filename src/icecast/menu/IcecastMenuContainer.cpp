#include "IcecastMenuContainer.h"
#include "AlsaCaptureMenuItem.h"
#include "IcecastAgentMenuItem.h"
#include "IcecastAgentClientMenuItem.h"

IcecastMenuContainer::IcecastMenuContainer() : MenuContainer(
	6,
	"Icecast",
	"Icecast")
{
	this->setContinueQuestion(true);
}

IcecastMenuContainer::~IcecastMenuContainer()
{

}

void IcecastMenuContainer::fillOptions()
{
	this->addMenuItem(new AlsaCaptureMenuItem(logSrv));
	this->addMenuItem(new IcecastAgentMenuItem(logSrv));
	this->addMenuItem(new IcecastAgentClientMenuItem(logSrv));
}

string IcecastMenuContainer::getHeader()
{
	return "";
}
