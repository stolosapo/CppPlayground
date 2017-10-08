#ifndef IcecastClient_h__
#define IcecastClient_h__

#include "config/IcecastClientConfig.h"
#include "IcecastProtocol.h"
#include "../tcpServer/client/ITcpClient.h"
#include "../tcpServer/lib/TcpConnector.h"
#include "../log/ILogService.h"

#ifdef ICECAST
#include <shout/shout.h>
#endif

class IcecastClient : public ITcpClient
{
private:
	ILogService *logSrv;

	TcpConnector *connector;
	TcpStream *stream;
	IcecastClientConfig* config;
	IcecastProtocol* protocol;

#ifdef ICECAST
	shout_t* shout;
#endif

	void loadConfig();
	void streamAudio();

	void initializeShout();

public:
	IcecastClient(ILogService *logSrv);
	virtual ~IcecastClient();

	virtual void action();	

};

#endif // IcecastClient_h__
