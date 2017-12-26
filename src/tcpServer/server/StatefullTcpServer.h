#ifndef StatefullTcpServer_h__
#define StatefullTcpServer_h__

#include <string>

#include "TcpServer.h"
#include "../ClientInfo.h"

#include "../../lib/exception/domain/DomainException.h"
#include "../../lib/exception/ExceptionMapper.h"
#include "../../lib/task/Locker.h"

using namespace std;

template<typename T>
class StatefullTcpServer : public TcpServer
{
private:
	T* state;

	Locker locker;

public:
	StatefullTcpServer(ILogService *logSrv);
	virtual ~StatefullTcpServer();

protected:
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
StatefullTcpServer<T>::initialize()
{
	TcpServer::initialize();

	state = createNewState();
}

template <typename T>
StatefullTcpServer<T>::safeStateMutation(ClientInfo *client, string input)
{
	locker.lock();

	try
	{
		stateMutation(client, input);
	}
	catch(DomainException& e)
	{
		logSrv->error(handle(e));
	}

	locker.unlock();
}

#endif // StatefullTcpServer_h__
