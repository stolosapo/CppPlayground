#include "NoiseStreamerMenuContainer.h"
#include "AlsaCaptureMenuItem.h"
#include "NoiseStreamerAgentMenuItem.h"
#include "NoiseStreamerAgentClientMenuItem.h"

NoiseStreamerMenuContainer::NoiseStreamerMenuContainer() : MenuContainer(
	6,
	"Icecast",
	"Icecast")
{
	this->setContinueQuestion(true);
}

NoiseStreamerMenuContainer::~NoiseStreamerMenuContainer()
{

}

void NoiseStreamerMenuContainer::fillOptions()
{
	this->addMenuItem(new AlsaCaptureMenuItem(logSrv));
	this->addMenuItem(new NoiseStreamerAgentMenuItem(logSrv));
	this->addMenuItem(new NoiseStreamerAgentClientMenuItem(logSrv));
}

string NoiseStreamerMenuContainer::getHeader()
{
	return "";
}
