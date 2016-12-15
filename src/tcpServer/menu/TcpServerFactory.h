#ifndef TcpServerFactory_h__
#define TcpServerFactory_h__

#include "ITcpServer.h"
#include "../../log/ILogService.h"

class TcpServerFactory
{
public:
	TcpServerFactory();
	~TcpServerFactory();
	
	static ITcpServer *create(ILogService *logSrv);
};

#endif // #ifndef TcpServerFactory_h__