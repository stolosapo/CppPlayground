#include "TcpMenuContainer.h"

#include "../server/TcpServerFactory.cpp"
#include "../client/TcpClientFactory.cpp"


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
	this->addMenuItem(2, TcpClientFactory::create(logSrv));
}

string TcpMenuContainer::getHeader()
{
	return "";
}
