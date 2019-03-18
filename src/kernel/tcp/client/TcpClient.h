#ifndef TcpClient_h__
#define TcpClient_h__

#include "ITcpClient.h"
#include "../config/TcpClientConfig.h"
#include "../protocol/ITcpProtocol.h"
#include "../lib/TcpConnector.h"
#include "../../log/ILogService.h"
#include "../../interruption/SignalService.h"

class TcpClient : public ITcpClient
{
private:
	TcpConnector *connector;
	TcpStream *stream;
	TcpClientConfig* config;

	SignalService* sigSrv;

	void finalizeClient(ClientInfo *client);

public:
	TcpClient(ILogService *logSrv, SignalService *sigSrv);
	virtual ~TcpClient();

	void start();
	virtual void action();

protected:
	InOut *in;
	ILogService *logSrv;

	ITcpProtocol *protocol;

	virtual ITcpProtocol* createProtocol();
	virtual string configFilename();
	virtual void loadConfig();
	virtual void initialize();

	virtual bool cycle(ClientInfo *client);

	virtual void processCommand(ClientInfo *client, string command);

};

#endif // TcpClient_h__
