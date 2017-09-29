#include "TcpMenuContainer.h"

#include "../server/TcpServerFactory.h"
#include "TcpServerMenuItem.h"
#include "MultiThreadServerMenuItem.h"
#include "TcpClientMenuItem.h"


TcpMenuContainer::TcpMenuContainer() : MenuContainer(
	3,
	"Tcp Client/Server",
	"Tcp Client/Server",
	3)
{

}

TcpMenuContainer::~TcpMenuContainer()
{

}

void TcpMenuContainer::fillOptions()
{
	this->addMenuItem(0, new TcpServerMenuItem(logSrv));
	this->addMenuItem(1, new MultiThreadServerMenuItem(logSrv));
	this->addMenuItem(2, new TcpClientMenuItem(logSrv));
}

string TcpMenuContainer::getHeader()
{
	return "";
}
