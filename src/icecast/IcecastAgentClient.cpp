#include "IcecastAgentClient.h"

#include "protocol/IcecastAgentProtocol.h"

IcecastAgentClient::IcecastAgentClient(
    ILogService *logSrv,
    SignalService *sigSrv,
    ArgumentService *argSrv)
	: TcpClient(logSrv, sigSrv),
    IcecastAgentClientArgumentAdapter(argSrv)
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
    if (hasAgentClientConfigFilename())
    {
        return getAgentClientConfigFilename();
    }

	return "icecast/icecastAgentClient.config";
}
