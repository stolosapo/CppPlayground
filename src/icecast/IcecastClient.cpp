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

	libShout = new LibShout(logSrv, config);

	libShout->initializeShout();

	try
	{
		libShout->startShout();

		// libShout->streamFile("03-TakeFive.mp3");

		while (playlist->hasNext(currentTrackNum))
		{
			string track = playlist->getNext(currentTrackNum);

			// cout << currentTrackNum << ") " << track << endl;

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
	playlist = new IcecastPlaylist(config);
	playlist->load();

	streamAudio();

	return;
}
