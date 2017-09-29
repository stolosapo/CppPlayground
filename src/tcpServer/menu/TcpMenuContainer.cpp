#include "TcpMenuContainer.h"

#include "../server/TcpServerFactory.h"
#include "../client/TcpClientFactory.h"
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
	this->addMenuItem(0, TcpServerFactory::create(logSrv, false));
	this->addMenuItem(1, TcpServerFactory::create(logSrv, true));
	this->addMenuItem(2, new TcpClientMenuItem(logSrv));
}

string TcpMenuContainer::getHeader()
{
	return "";
}
