#include <iostream>
#include <string>
#include "TcpServerFactory.cpp"
#include "TcpClientFactory.cpp"
#include "../../shared/Container.h"

using namespace std;

class TcpContainer : public Container
{
public:
	TcpContainer() : Container(
		3, 
		"Tcp Client/Server",
		"Tcp Client/Server",
		3)
	{
		
	}

	virtual ~TcpContainer()
	{

	}

protected:
	virtual void fillOptions()
	{
		this->addMenuItem(0, TcpServerFactory::create(logSrv, false));
		this->addMenuItem(1, TcpServerFactory::create(logSrv, true));
		this->addMenuItem(2, TcpClientFactory::create(logSrv));
	}

	virtual string getHeader()
	{
		return "";
	}

};