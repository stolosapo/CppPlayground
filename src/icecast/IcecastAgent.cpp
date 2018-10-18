#include "IcecastAgent.h"

#include "protocol/IcecastAgentTasks.h"


IcecastAgent::IcecastAgent(ILogService *logSrv, SignalService *sigSrv, ITimeService *timeSrv, AudioTagService *tagSrv, ArgumentService *argSrv)
	: TcpServer(logSrv, sigSrv, timeSrv), IcecastAgentArgumentAdapter(argSrv), tagSrv(tagSrv)
{
	icecastThread = NULL;
	icecast = NULL;
}

IcecastAgent::~IcecastAgent()
{
	disposeIcecast();
}

IcecastAgentProtocol* IcecastAgent::agentProtocol()
{
	return (IcecastAgentProtocol*) getProtocol();
}

ITcpProtocol* IcecastAgent::createProtocol()
{
	return (ITcpProtocol*) new IcecastAgentProtocol(true);
}

string IcecastAgent::configFilename()
{
    if (hasAgentConfigFilename())
    {
        return getAgentConfigFilename();
    }

	return "icecastAgent.config";
}

IcecastClient* IcecastAgent::createNewIcecast()
{
    return new IcecastClient(logSrv, sigSrv, tagSrv);
}

void IcecastAgent::disposeIcecast()
{
    if (icecastThread != NULL)
    {
        logger()->trace("Waiting Icecast thread to finnished..");
        delete icecastThread;
        logger()->trace("Icecast thread finnished!");
    }

    if (icecast != NULL)
    {
        delete icecast;
    }
}

void IcecastAgent::startIcecast()
{
	disposeIcecast();

    icecast = createNewIcecast();

	icecastThread = agentProtocol()->startTask(icecast_start_client, this);
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
