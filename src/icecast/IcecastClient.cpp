#include "IcecastClient.h"

#include "config/IcecastClientConfigLoader.h"
#include "exception/IcecastDomainErrorCode.h"
#include "IcecastPlaylist.h"

#include "../kernel/converter/Convert.h"
#include "../kernel/exception/domain/DomainException.h"

#include "../kernel/di/GlobalAppContext.h"
#include "../kernel/interruption/SignalService.h"


const char* IcecastClient::USER_AGENT = "NoiseStreamer";


IcecastClient::IcecastClient(ILogService *logSrv, SignalService *sigSrv) : logSrv(logSrv), sigSrv(sigSrv)
{
	this->config = NULL;
	this->libShout = NULL;
	this->playlist = NULL;
}

IcecastClient::~IcecastClient()
{
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

string IcecastClient::version()
{
	string major = Convert<const int>::NumberToString(MAJOR_VERSION);
	string minor = Convert<const int>::NumberToString(MINOR_VERSION);
	string patch = Convert<const int>::NumberToString(PATCH_VERSION);

	return major + "." + minor + "." + patch;
}

string IcecastClient::agentVersion()
{
	return string(USER_AGENT) + "/" + version();
}

void IcecastClient::loadConfig()
{
	IcecastClientConfigLoader* loader = new IcecastClientConfigLoader("icecast.config");

	this->config = loader->load();

	delete loader;
}

void IcecastClient::streamAudio()
{
	libShout = new LibShout(logSrv, sigSrv, config);

	libShout->initializeShout();

	try
	{
		libShout->startShout();

		while (playlist->hasNext() && !sigSrv->gotSigIntAndReset())
		{

			string track = playlist->getNext();

			string i = Convert<int>::NumberToString(playlist->getCurrentIndex());
			string c = Convert<int>::NumberToString(playlist->getHistoryCount());
			string s = Convert<int>::NumberToString(playlist->size());

			logSrv->info("Index: " + i + " (" + c + "/" + s + ")");

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
