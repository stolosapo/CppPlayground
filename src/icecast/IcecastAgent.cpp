#include "IcecastAgent.h"


IcecastAgent::IcecastAgent(ILogService *logSrv, SignalService *sigSrv, AudioTagService *tagSrv)
	: TcpServer(logSrv, sigSrv)
{
	icecast = new IcecastClient(logSrv, sigSrv, tagSrv);
}

IcecastAgent::~IcecastAgent()
{
	delete icecast;
}

IcecastAgentProtocol* IcecastAgent::agentProtocol()
{
	return (IcecastAgentProtocol*) getProtocol();
}

ITcpProtocol* IcecastAgent::createProtocol()
{
	return (ITcpProtocol*) new IcecastAgentProtocol(true);
}

const char* IcecastAgent::configFilename()
{
	return "icecastAgent.config";
}

void IcecastAgent::startIcecast()
{
	icecastThread = agentProtocol()->startTask("start", icecast);
}

void IcecastAgent::initialize()
{
	TcpServer::initialize();

	startIcecast();
}

bool IcecastAgent::validateCommand(string command)
{
	if (TcpServer::validateCommand(command))
	{
		return true;
	}

	return agentProtocol()->taskExist(command);
}

void IcecastAgent::processCommand(ClientInfo *client, string command)
{
	TcpStream *stream = client->getStream();

	agentProtocol()->runTask(command, client);

	stream->send(command);
}
