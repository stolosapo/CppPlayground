#include "IcecastClient.h"

#include "config/IcecastClientConfigLoader.h"
#include "exception/IcecastDomainErrorCode.h"
#include "../audio/mp3/Mp3Parser.h"
#include "IcecastPlaylist.h"

#include "../lib/converter/Convert.h"
#include "../lib/exception/domain/DomainException.h"


IcecastClient::IcecastClient(ILogService *logSrv)
{
	this->logSrv = logSrv;
}

IcecastClient::~IcecastClient()
{
	if (protocol != NULL)
	{
		// delete protocol;
	}

	if (config != NULL)
	{
		// delete config;
	}

	if (libShout != NULL)
	{
		// delete libShout;
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

	libShout = new LibShout(logSrv, config);

	libShout->initializeShout();

	try
	{
		libShout->startShout();

		IcecastPlaylist playlist(config);
		playlist.load();

		while (playlist.hasNext(currentTrackNum))
		{
			string track = playlist.getNext(currentTrackNum);

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

	streamAudio();

	return;
}
