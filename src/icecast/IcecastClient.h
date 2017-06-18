#ifndef IcecastClient_h__
#define IcecastClient_h__

#include "config/IcecastClientConfig.h"
#include "../tcpServer/menu/ITcpClient.h"
#include "../tcpServer/TcpConnector.h"
#include "../log/ILogService.h"

class IcecastClient : public ITcpClient
{
private:
	string newLine;

	ILogService *logSrv;

	TcpConnector *connector;
	TcpStream *stream;
	IcecastClientConfig* config;

	void test();

	void loadConfig();
	void initialize();

public:
	IcecastClient(ILogService *logSrv);
	virtual ~IcecastClient();

	virtual void action();	

};

#endif // IcecastClient_h__
