#include "IcecastAgent.h"


IcecastAgent::IcecastAgent(ILogService *logSrv, SignalService *sigSrv, AudioTagService *tagSrv)
	: TcpServer(logSrv, sigSrv)
{
	icecastThread = NULL;
	icecast = new IcecastClient(logSrv, sigSrv, tagSrv);
}

IcecastAgent::~IcecastAgent()
{
	if (icecastThread != NULL)
	{
		cout << "Before wait" << endl;
		logger()->trace("Waiting Icecast thread to finnished..");
		icecastThread->wait();
		cout << "After wait" << endl;
		logger()->trace("Icecast thread finnished!");
		delete icecastThread;
	}

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

IcecastClient* IcecastAgent::getIcecast()
{
	return icecast;
}

void IcecastAgent::startIcecast()
{
	icecastThread = agentProtocol()->startTask("start", this);
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

	agentProtocol()->runTask(command, this);

	stream->send(command);
}
