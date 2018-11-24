#include "IcecastAgent.h"

#include "protocol/IcecastAgentTasks.h"
#include "exception/IcecastDomainErrorCode.h"

#include "../kernel/configuration/ConfigLoader.h"


IcecastAgent::IcecastAgent(
    ILogService *logSrv,
    SignalService *sigSrv,
    ITimeService *timeSrv,
    AudioTagService *tagSrv,
    ArgumentService *argSrv,
    AudioEncodingService *encSrv)
	: TcpServer(logSrv, sigSrv, timeSrv),
    IcecastAgentArgumentAdapter(argSrv),
    tagSrv(tagSrv),
    encSrv(encSrv)
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

IcecastAgentConfig* IcecastAgent::agentConfig()
{
    return (IcecastAgentConfig*) this->config;
}

IcecastClient* IcecastAgent::icecastClient()
{
    if (icecast == NULL)
    {
        throw DomainException(IcecastDomainErrorCode::ICS0025);
    }

    return icecast;
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

	return "icecast/icecastAgent.config";
}

void IcecastAgent::loadConfig()
{
	string file = configFilename();

    ConfigLoader<IcecastAgentConfig> loader(file);
    this->config = (TcpServerConfig*) loader.load();

	logSrv->info("Configuration Loaded. '" + file + "'");
}

IcecastClient* IcecastAgent::createNewIcecast()
{
    return new IcecastClient(logSrv, sigSrv, tagSrv, encSrv, agentConfig()->getIcecastConfig());
}

void IcecastAgent::disposeIcecast()
{
    if (icecastThread != NULL)
    {
        logger()->trace("Waiting Icecast thread to finnished..");
        delete icecastThread;
        logger()->trace("Icecast thread finnished!");
    }

    disposeIcecastClient();
}

void IcecastAgent::disposeIcecastClient()
{
    if (icecast != NULL)
    {
        delete icecast;
        icecast = NULL;
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

    string strValue = command;

    try
    {
    	void* retval = agentProtocol()->runTask(command, this);

    	if (retval != NULL)
    	{
    		string *str = static_cast<string*>(retval);
    		strValue = *str;

    		delete str;
    	}
    }
    catch(DomainException& e)
    {
        strValue = handle(e);
        logSrv->error(strValue);
    }
    catch(RuntimeException& e)
    {
        strValue = handle(e);
        logSrv->error(strValue);
    }
    catch(exception& e)
    {
        strValue = e.what();
        logSrv->error(strValue);
    }

	stream->send(strValue);
}
