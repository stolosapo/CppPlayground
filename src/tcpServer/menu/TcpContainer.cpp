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
		2)
	{
		
	}

	virtual ~TcpContainer()
	{

	}

protected:
	virtual void fillOptions()
	{
		this->addMenuItem(0, TcpServerFactory::create(logSrv));
		this->addMenuItem(1, TcpClientFactory::create(logSrv));
	}

	virtual string getHeader()
	{
		return "";
	}

};