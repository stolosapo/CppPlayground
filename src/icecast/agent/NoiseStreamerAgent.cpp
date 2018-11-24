#include "NoiseStreamerAgent.h"

#include "../protocol/NoiseStreamerAgentTasks.h"
#include "../exception/NoiseStreamerDomainErrorCode.h"

#include "../../kernel/configuration/ConfigLoader.h"


NoiseStreamerAgent::NoiseStreamerAgent(
    ILogService *logSrv,
    SignalService *sigSrv,
    ITimeService *timeSrv,
    AudioTagService *tagSrv,
    ArgumentService *argSrv,
    AudioEncodingService *encSrv)
	: TcpServer(logSrv, sigSrv, timeSrv),
    NoiseStreamerAgentArgumentAdapter(argSrv),
    tagSrv(tagSrv),
    encSrv(encSrv)
{
	icecastThread = NULL;
	icecast = NULL;
}

NoiseStreamerAgent::~NoiseStreamerAgent()
{
	disposeIcecast();
}

NoiseStreamerAgentProtocol* NoiseStreamerAgent::agentProtocol()
{
	return (NoiseStreamerAgentProtocol*) getProtocol();
}

NoiseStreamerAgentConfig* NoiseStreamerAgent::agentConfig()
{
    return (NoiseStreamerAgentConfig*) this->config;
}

NoiseStreamer* NoiseStreamerAgent::icecastClient()
{
    if (icecast == NULL)
    {
        throw DomainException(NoiseStreamerDomainErrorCode::ICS0025);
    }

    return icecast;
}

ITcpProtocol* NoiseStreamerAgent::createProtocol()
{
	return (ITcpProtocol*) new NoiseStreamerAgentProtocol(true);
}

string NoiseStreamerAgent::configFilename()
{
    if (hasAgentConfigFilename())
    {
        return getAgentConfigFilename();
    }

	return "icecast/icecastAgent.config";
}

void NoiseStreamerAgent::loadConfig()
{
	string file = configFilename();

    ConfigLoader<NoiseStreamerAgentConfig> loader(file);
    this->config = (TcpServerConfig*) loader.load();

	logSrv->info("Configuration Loaded. '" + file + "'");
}

NoiseStreamer* NoiseStreamerAgent::createNewIcecast()
{
    return new NoiseStreamer(logSrv, sigSrv, tagSrv, encSrv, agentConfig()->getIcecastConfig());
}

void NoiseStreamerAgent::disposeIcecast()
{
    if (icecastThread != NULL)
    {
        logger()->trace("Waiting Icecast thread to finnished..");
        delete icecastThread;
        logger()->trace("Icecast thread finnished!");
    }

    disposeIcecastClient();
}

void NoiseStreamerAgent::disposeIcecastClient()
{
    if (icecast != NULL)
    {
        delete icecast;
        icecast = NULL;
    }
}

void NoiseStreamerAgent::startIcecast()
{
	disposeIcecast();

    icecast = createNewIcecast();

	icecastThread = agentProtocol()->startTask(icecast_start_client, this);
}

void NoiseStreamerAgent::initialize()
{
	TcpServer::initialize();

	startIcecast();
}

bool NoiseStreamerAgent::validateCommand(string command)
{
	if (TcpServer::validateCommand(command))
	{
		return true;
	}

	return agentProtocol()->taskExist(command);
}

void NoiseStreamerAgent::processCommand(ClientInfo *client, string command)
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
