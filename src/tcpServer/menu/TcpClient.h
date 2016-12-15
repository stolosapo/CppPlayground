#ifndef TcpClient_h__
#define TcpClient_h__

#include "ITcpClient.h"
#include "../TcpConnector.h"
#include "../../log/ILogService.h"

class TcpClient : public ITcpClient
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
	TcpClient(ILogService *logSrv);
	virtual ~TcpClient();

	void start();
	virtual void action();
};

#endif // TcpClient_h__