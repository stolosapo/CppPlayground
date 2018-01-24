#include "IcecastClient.h"

#include "config/IcecastClientConfigLoader.h"
#include "exception/IcecastDomainErrorCode.h"
#include "../audio/mp3/Mp3Parser.h"
#include "IcecastPlaylist.h"

#include "../kernel/converter/Convert.h"
#include "../kernel/exception/domain/DomainException.h"

#include "../kernel/di/GlobalAppContext.h"
#include "../kernel/interruption/SignalService.h"


IcecastClient::IcecastClient(ILogService *logSrv)
{
	this->logSrv = logSrv;

	this->protocol = NULL;
	this->config = NULL;
	this->libShout = NULL;
	this->playlist = NULL;
}

IcecastClient::~IcecastClient()
{
	if (protocol != NULL)
	{
		delete protocol;
	}

	if (config != NULL)
	{
		delete config;
	}

	if (libShout != NULL)
	{
		delete libShout;
	}

	if (playlist != NULL)
	{
		delete playlist;
	}
}

void IcecastClient::loadConfig()
{
	IcecastClientConfigLoader* loader = new IcecastClientConfigLoader("icecast.config");

	this->config = loader->load();

	this->protocol = new IcecastProtocol(this->config);

	delete loader;
}

void IcecastClient::streamAudio()
{
	int currentTrackNum = 0;

	SignalService* sigSrv = inject<SignalService>("signalService");

	libShout = new LibShout(logSrv, config);

	libShout->initializeShout();

	try
	{
		libShout->startShout();

		while (playlist->hasNext(currentTrackNum))
		{
			/* Check for Interruption */
			if (sigSrv->signaled(SIGINT) == 1)
			{
				logSrv->debug("Playlist stopped");
				sigSrv->reset(SIGINT);
				
				break;
			}

			string track = playlist->getNext(currentTrackNum);

			libShout->streamFile(track.c_str());
		}

	}
	catch (DomainException& e)
	{
		logSrv->error(e.fullError());
	}

	libShout->finilizeShout();
}

void IcecastClient::action()
{
	loadConfig();

	/* Load playlist */
	playlist = new IcecastPlaylist(logSrv, config);
	playlist->load();

	streamAudio();

	return;
}
