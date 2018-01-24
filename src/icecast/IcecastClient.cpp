#include "IcecastClient.h"

#include "config/IcecastClientConfigLoader.h"
#include "exception/IcecastDomainErrorCode.h"
#include "../audio/mp3/Mp3Parser.h"
#include "IcecastPlaylist.h"

#include "../kernel/converter/Convert.h"
#include "../kernel/exception/domain/DomainException.h"

#include "../kernel/di/GlobalAppContext.h"
#include "../kernel/interruption/SignalService.h"


const char* IcecastClient::USER_AGENT = "NoiseStreamer";


IcecastClient::IcecastClient(ILogService *logSrv)
{
	this->logSrv = logSrv;

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
	int currentTrackNum = 0;
	int trackCnt = 0;

	SignalService* sigSrv = inject<SignalService>("signalService");

	libShout = new LibShout(logSrv, config);

	libShout->initializeShout();

	try
	{
		libShout->startShout();

		while (playlist->hasNext(currentTrackNum, trackCnt))
		{
			/* Check for Interruption */
			if (sigSrv->signaled(SIGINT) == 1)
			{
				logSrv->debug("Playlist stopped");
				sigSrv->reset(SIGINT);
				
				break;
			}

			string track = playlist->getNext(currentTrackNum);

			string i = Convert<int>::NumberToString(currentTrackNum);
			string c = Convert<int>::NumberToString(trackCnt + 1);
			string s = Convert<int>::NumberToString(playlist->size());

			logSrv->info("Index: " + i + " (" + c + "/" + s + ")");

			libShout->streamFile(track.c_str());

			trackCnt++;
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
