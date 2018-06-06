#ifndef HttpServer_h__
#define HttpServer_h__

#include <string>

#include "../../tcp/server/TcpServer.h"

using namespace std;

class HttpServer : public TcpServer
{
protected:
	virtual ITcpProtocol* createProtocol();
	virtual const char* configFilename();

public:
	HttpServer(ILogService *logSrv, SignalService *sigSrv, ITimeService *timeSrv);
	virtual ~HttpServer();

};

#endif // HttpServer_h__
