#ifndef TcpClientFactory_h__
#define TcpClientFactory_h__

#include "ITcpClient.h"
#include "../../log/ILogService.h"

class TcpClientFactory
{
public:
	TcpClientFactory();
	~TcpClientFactory();
	
	static ITcpClient *create(ILogService *logSrv);
};

#endif // #ifndef TcpClientFactory_h__