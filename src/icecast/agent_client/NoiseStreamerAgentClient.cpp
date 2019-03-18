#include "NoiseStreamerAgentClient.h"

#include "../protocol/NoiseStreamerAgentProtocol.h"

NoiseStreamerAgentClient::NoiseStreamerAgentClient(
    ILogService *logSrv,
    SignalService *sigSrv,
    ArgumentService *argSrv)
	: TcpClient(logSrv, sigSrv),
    NoiseStreamerAgentClientArgumentAdapter(argSrv)
{

}

NoiseStreamerAgentClient::~NoiseStreamerAgentClient()
{

}

ITcpProtocol* NoiseStreamerAgentClient::createProtocol()
{
	return (ITcpProtocol*) new NoiseStreamerAgentProtocol(false);
}

string NoiseStreamerAgentClient::configFilename()
{
    if (hasAgentClientConfigFilename())
    {
        return getAgentClientConfigFilename();
    }

	return "icecast/icecastAgentClient.config";
}
