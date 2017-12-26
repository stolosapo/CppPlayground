#ifndef TcpServerFactory_h__
#define TcpServerFactory_h__

#include "ITcpServer.h"
#include "../../kernel/log/ILogService.h"

class TcpServerFactory
{
public:
	TcpServerFactory();
	~TcpServerFactory();

	static ITcpServer *create(ILogService *logSrv);
};

#endif // TcpServerFactory_h__
