#include <iostream>
#include <string>
#include "TcpClient.h"

using namespace std;

/*********************************
*
*		CONSTRUCTORS
*
**********************************/
TcpClient::TcpClient(ILogService *logSrv) : MenuItem()
{
	this->logSrv = logSrv;

	this->setId(2);
	this->setName("Tcp Client");
	this->setTitle("Tcp Client");
	this->setDescription("The First Kube Tcp Client");
}

TcpClient::~TcpClient()
{

}


/*********************************
*
*		PRIVATE METHODS
*
**********************************/
void TcpClient::test()
{
	this->logSrv->info("This is a Tcp test");
}


/*********************************
*
*		PUBLIC METHODS
*
**********************************/
void TcpClient::action()
{
	this->identify();
	this->logSrv->outString("\n\n");

	this->test();
}