#include "HttpServer.h"

#include "../protocol/HttpProtocol.h"

HttpServer::HttpServer(ILogService *logSrv, SignalService *sigSrv, ITimeService *timeSrv)
	: TcpServer(logSrv, sigSrv, timeSrv)
{

}

HttpServer::~HttpServer()
{

}

ITcpProtocol* HttpServer::createProtocol()
{
	return (ITcpProtocol*) new HttpProtocol(true);
}

string HttpServer::configFilename()
{
	return "http/httpServer.config";
}
