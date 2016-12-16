#ifndef TcpServerConfig_h__
#define TcpServerConfig_h__

#include "ITcpClient.h"
#include "../TcpConnector.h"
#include "../../log/ILogService.h"

class TcpServerConfig : public ITcpClient
{
private:
	static const int DEFAULT_PORT = 51717;
	static const char* DEFAULT_HOSTNAME;

	ILogService *logSrv;

	int port;
	const char* hostname;

	TcpConnector *connector;
	TcpStream *stream;

	void test();
	bool askServerPermission();
	
public:
	TcpServerConfig(ILogService *logSrv);
	virtual ~TcpServerConfig();

	void start();
	virtual void action();
};

#endif // TcpServerConfig_h__