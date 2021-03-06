#include "TcpMenuContainer.h"

#include "../kernel/tcp/server/TcpServerFactory.h"
#include "TcpServerMenuItem.h"
#include "TcpClientMenuItem.h"


TcpMenuContainer::TcpMenuContainer() : MenuContainer(
	3,
	"Tcp Client/Server",
	"Tcp Client/Server")
{

}

TcpMenuContainer::~TcpMenuContainer()
{

}

void TcpMenuContainer::fillOptions()
{
	this->addMenuItem(new TcpServerMenuItem(logSrv));
	this->addMenuItem(new TcpClientMenuItem(logSrv));
}

string TcpMenuContainer::getHeader()
{
	return "";
}
