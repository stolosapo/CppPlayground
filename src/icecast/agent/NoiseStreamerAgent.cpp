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
	streamerThread = NULL;
	nss = NULL;
}

NoiseStreamerAgent::~NoiseStreamerAgent()
{
	disposeStreamerThread();
}

NoiseStreamerAgentProtocol* NoiseStreamerAgent::agentProtocol()
{
	return (NoiseStreamerAgentProtocol*) getProtocol();
}

NoiseStreamerAgentConfig* NoiseStreamerAgent::agentConfig()
{
    return (NoiseStreamerAgentConfig*) this->config;
}

NoiseStreamer* NoiseStreamerAgent::noiseStreamer()
{
    if (nss == NULL)
    {
        throw DomainException(NoiseStreamerDomainErrorCode::NSS0025);
    }

    return nss;
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

NoiseStreamer* NoiseStreamerAgent::createNewStreamer()
{
    return new NoiseStreamer(logSrv,
        sigSrv,
        timeSrv,
        tagSrv,
        encSrv,
        agentConfig()->getIcecastConfig());
}

void NoiseStreamerAgent::disposeStreamerThread()
{
    if (streamerThread != NULL)
    {
        logger()->trace("Waiting Icecast thread to finnished..");
        delete streamerThread;
        logger()->trace("Icecast thread finnished!");
    }

    disposeNoiseStreamer();
}

void NoiseStreamerAgent::disposeNoiseStreamer()
{
    if (nss != NULL)
    {
        delete nss;
        nss = NULL;
    }
}

void NoiseStreamerAgent::startStreamer()
{
	disposeStreamerThread();

    nss = createNewStreamer();

	streamerThread = agentProtocol()->startTask(nss_start_client, this);
}

void NoiseStreamerAgent::initialize()
{
	TcpServer::initialize();

	startStreamer();
}

bool NoiseStreamerAgent::validateCommand(string command)
{
	if (TcpServer::validateCommand(command))
	{
		return true;
	}

	return agentProtocol()->parametrizedTaskExist(command);
}

void NoiseStreamerAgent::processCommand(ClientInfo *client, string command)
{
	TcpStream *stream = client->getStream();

    string strValue = command;

    try
    {
    	// void* retval = agentProtocol()->runTask(command, this);
    	void* retval = agentProtocol()->runParametrizedTask(command, this);

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
