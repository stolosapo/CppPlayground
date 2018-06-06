#include "IcecastAgent.h"


IcecastAgent::IcecastAgent(ILogService *logSrv, SignalService *sigSrv, ITimeService *timeSrv, AudioTagService *tagSrv)
	: TcpServer(logSrv, sigSrv, timeSrv)
{
	icecastThread = NULL;
	icecast = new IcecastClient(logSrv, sigSrv, tagSrv);
}

IcecastAgent::~IcecastAgent()
{
	if (icecastThread != NULL)
	{
		logger()->trace("Waiting Icecast thread to finnished..");
		icecastThread->wait();
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

	void* retval = agentProtocol()->runTask(command, this);

	string strValue = command;

	if (retval != NULL)
	{
		string *str = static_cast<string*>(retval);
		strValue = *str;

		delete str;
	}

	stream->send(strValue);
}
