#ifndef IcecastClient_h__
#define IcecastClient_h__

#include "config/IcecastClientConfig.h"
#include "IcecastProtocol.h"
#include "../tcpServer/client/ITcpClient.h"
#include "../tcpServer/lib/TcpConnector.h"
#include "../log/ILogService.h"

class IcecastClient : public ITcpClient
{
private:
	ILogService *logSrv;

	TcpConnector *connector;
	TcpStream *stream;
	IcecastClientConfig* config;
	IcecastProtocol* protocol;

	void loadConfig();
	void streamAudio();

public:
	IcecastClient(ILogService *logSrv);
	virtual ~IcecastClient();

	virtual void action();	

};

#endif // IcecastClient_h__
