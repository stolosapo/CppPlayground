#ifndef TcpClient_h__
#define TcpClient_h__

#include "ITcpClient.h"
#include "../config/TcpClientConfig.h"
#include "../protocol/ITcpProtocol.h"
#include "../lib/TcpConnector.h"
#include "../../kernel/log/ILogService.h"

class TcpClient : public ITcpClient
{
private:
	InOut *in;
	ILogService *logSrv;

	ITcpProtocol *protocol;
	TcpConnector *connector;
	TcpStream *stream;
	TcpClientConfig* config;

	void finalizeClient(ClientInfo *client);

public:
	TcpClient(ILogService *logSrv);
	virtual ~TcpClient();

	void start();
	virtual void action();

protected:
	virtual void loadConfig();
	virtual void initialize();

	virtual bool cycle(ClientInfo *client);

	virtual void processCommand(ClientInfo *client, string command);
	
};

#endif // TcpClient_h__
