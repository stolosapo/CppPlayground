#include "IcecastAgentClient.h"

#include "protocol/IcecastAgentProtocol.h"

IcecastAgentClient::IcecastAgentClient(ILogService *logSrv, SignalService *sigSrv)
	: TcpClient(logSrv, sigSrv)
{

}

IcecastAgentClient::~IcecastAgentClient()
{

}

ITcpProtocol* IcecastAgentClient::createProtocol()
{
	return (ITcpProtocol*) new IcecastAgentProtocol(false);
}

string IcecastAgentClient::configFilename()
{
	return "icecast/icecastAgentClient.config";
}
