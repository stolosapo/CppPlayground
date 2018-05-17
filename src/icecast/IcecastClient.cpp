#include "IcecastClient.h"

#include "config/IcecastClientConfigLoader.h"
#include "exception/IcecastDomainErrorCode.h"
#include "IcecastPlaylist.h"

#include "../kernel/converter/Convert.h"
#include "../kernel/utils/FileHelper.h"
#include "../kernel/exception/domain/DomainException.h"

#include "../kernel/di/GlobalAppContext.h"
#include "../kernel/interruption/SignalService.h"

#include "../kernel/audio/playlist/PlaylistHandlerFactory.h"


const char* IcecastClient::USER_AGENT = "NoiseStreamer";


IcecastClient::IcecastClient(ILogService *logSrv, SignalService *sigSrv, AudioTagService *tagSrv)
	: Version(1, 0, 0), logSrv(logSrv), sigSrv(sigSrv), tagSrv(tagSrv)
{
	this->config = NULL;
	this->libShout = NULL;
	playlistHandlerFactory = NULL;
	playlistHandler = NULL;
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

	if (playlistHandler != NULL)
	{
		delete playlistHandler;
	}

	if (playlistHandlerFactory != NULL)
	{
		delete playlistHandlerFactory;
	}
}

string IcecastClient::agentVersion()
{
	// return string(USER_AGENT) + "/" + string(version());
	return string(USER_AGENT);
}

void IcecastClient::logNowPlaying(PlaylistItem item)
{
	string i = Convert<int>::NumberToString(item.getTrackIndex());

	logSrv->info("Index: " + i);
	logSrv->info("-- Playing: " + item.getTrack());
	logSrv->info("-- Track: " + item.getTrackTitle());
}

void IcecastClient::loadConfig()
{
	IcecastClientConfigLoader loader("icecast.config");

	this->config = loader.load();
}

void IcecastClient::loadPlaylist()
{
	string playlistFile = config->getPlaylist();

	playlistHandlerFactory = 
		new PlaylistHandlerFactory(playlistFile.c_str(), "playlist.history.pls", SIMPLE, true);

	playlistHandler = playlistHandlerFactory->create();
	playlistHandler->load();
	int size = playlistHandler->playlistSize();

	logSrv->info("Playlist: '" + playlistFile + "' loaded, with '" + Convert<int>::NumberToString(size) + "' tracks");

	playlistHandler->exportPlaylistMetadata("playlist.metadata.json", 4);
}

void IcecastClient::streamAudio()
{
	libShout = new LibShout(logSrv, sigSrv, config);
	libShout->initializeShout();

	try
	{
		libShout->startShout();

		while (playlistHandler->hasNext() && !sigSrv->gotSigIntAndReset())
		{
			PlaylistItem item = playlistHandler->nextTrack();

			string track = item.getTrack();
			string trackTitle = item.getTrackTitle();

			logNowPlaying(item);

			libShout->streamFile(track.c_str(), trackTitle.c_str());
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

	loadPlaylist();
	
	streamAudio();
}
