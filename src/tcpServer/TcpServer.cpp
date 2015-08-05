#include <iostream>
#include <string>
#include "TcpServer.h"

using namespace std;

/*********************************
*
*		CONSTRUCTORS
*
**********************************/
TcpServer::TcpServer(ILogService *logSrv) : MenuItem()
{
	this->logSrv = logSrv;

	this->setId(1);
	this->setName("Tcp Server");
	this->setTitle("Tcp Server");
	this->setDescription("The First Kube Tcp Server");
}

TcpServer::~TcpServer()
{

}


/*********************************
*
*		PRIVATE METHODS
*
**********************************/
void TcpServer::activate()
{
	this->isActive = true;
	this->logSrv->info("Server activated");
}

void TcpServer::passivate()
{
	this->isActive = false;
	this->logSrv->info("Server passivated");
}


/*********************************
*
*		PUBLIC METHODS
*
**********************************/
void TcpServer::start()
{
	this->logSrv->info("Tcp Server started and is waiting");
}

void TcpServer::action()
{
	this->identify();
	this->logSrv->outString("\n\n");

	this->activate();

	this->start();

	this->passivate();
}