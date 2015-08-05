#include <iostream>
#include <string>
#include "TcpServer.h"
#include "TcpClient.h"
#include "../shared/Container.h"

using namespace std;

class TcpContainer : public Container
{
public:
	TcpContainer() : Container(
		2, 
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
		this->addMenuItem(0, new TcpServer(logSrv));
		this->addMenuItem(1, new TcpClient(logSrv));
	}

};