#include "TcpMenuContainer.h"

#include "../server/TcpServerFactory.h"
#include "TcpServerMenuItem.h"
#include "TcpClientMenuItem.h"


TcpMenuContainer::TcpMenuContainer() : MenuContainer(
	3,
	"Tcp Client/Server",
	"Tcp Client/Server",
	2)
{

}

TcpMenuContainer::~TcpMenuContainer()
{

}

void TcpMenuContainer::fillOptions()
{
	this->addMenuItem(0, new TcpServerMenuItem(logSrv));
	this->addMenuItem(1, new TcpClientMenuItem(logSrv));
}

string TcpMenuContainer::getHeader()
{
	return "";
}
