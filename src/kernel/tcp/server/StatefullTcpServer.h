#ifndef StatefullTcpServer_h__
#define StatefullTcpServer_h__

#include <iostream>
#include <string>

#include "TcpServer.h"
#include "../ClientInfo.h"

#include "../../exception/domain/DomainException.h"
#include "../../exception/ExceptionMapper.h"
#include "../../task/Locker.h"

using namespace std;

template<typename T>
class StatefullTcpServer : public TcpServer
{
private:
	Locker locker;

public:
	StatefullTcpServer(ILogService *logSrv);
	virtual ~StatefullTcpServer();

protected:
	T* state;
	
	virtual T* createNewState() = 0;

	virtual void initialize();

	virtual void safeStateMutation(ClientInfo *client, string input);
	virtual void stateMutation(ClientInfo *client, string input) = 0;

};









template <typename T>
StatefullTcpServer<T>::StatefullTcpServer(ILogService *logSrv) : TcpServer(logSrv)
{
	locker.init();	
}

template <typename T>
StatefullTcpServer<T>::~StatefullTcpServer()
{
	locker.destroy();

	if (state != NULL)
	{
		delete state;
	}
}

template <typename T>
void StatefullTcpServer<T>::initialize()
{
	TcpServer::initialize();

	state = createNewState();
}

template <typename T>
void StatefullTcpServer<T>::safeStateMutation(ClientInfo *client, string input)
{
	locker.lock();

	try
	{
		stateMutation(client, input);
	}
	catch(DomainException& e)
	{
		ILogService* logger = ((StatefullTcpServer<T>*) client->getServer())->logger();
		
		logger->error(handle(e));

		logger = NULL;
	}

	locker.unlock();
}

#endif // StatefullTcpServer_h__
