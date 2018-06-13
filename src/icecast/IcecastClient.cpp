#include "IcecastClient.h"

#include "config/IcecastClientConfigLoader.h"
#include "exception/IcecastDomainErrorCode.h"

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

	numberOfPlayedTracks = 0;
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
	return string(USER_AGENT) + "/" + string(version());
}

void IcecastClient::logNowPlaying(PlaylistItem item)
{
	string i = Convert<int>::NumberToString(item.getTrackIndex());

	logSrv->info("Index: " + i);
	logSrv->info("-- Playing: " + item.getTrack());
	logSrv->info("-- Track: " + item.getTrackTitle());
}

int IcecastClient::getNumberOfPlayedTracks()
{
	return numberOfPlayedTracks;
}

void IcecastClient::loadConfig()
{
	IcecastClientConfigLoader loader("icecast.config");

	this->config = loader.load();
}

void IcecastClient::initializePlaylist()
{
	string playlistFile = config->getPlaylist();
	string historyFile = config->getHistory();
	const char* metadataFile = config->getMetadata().c_str();
	PlaylistStrategyType type = config->getStrategyType();
	bool repeat = config->getRepeat();

	if (type == NONE)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0022);
	}

	playlistHandlerFactory =
		new PlaylistHandlerFactory(playlistFile.c_str(), historyFile, type, repeat);

	playlistHandler = playlistHandlerFactory->create();

	logSrv->info("Icecast playlist initialized!");
}

void IcecastClient::loadPlaylist()
{
	string playlistFile = config->getPlaylist();
	playlistHandler->load();
	int size = playlistHandler->playlistSize();

	logSrv->info("Playlist: '" + playlistFile + "' loaded, with '" + Convert<int>::NumberToString(size) + "' tracks");
}

void IcecastClient::initializeShout()
{
	libShout = new LibShout(logSrv, sigSrv);
	libShout->initializeShout();

	string shoutVersion = libShout->shoutFullVersion();
	string clientVersion = agentVersion();
	string fullVersion = clientVersion + " " + shoutVersion;

	libShout->setAgent(fullVersion);
	libShout->setProtocolHttp();
	libShout->setHost(config->getHostname());
	libShout->setPort(Convert<unsigned short>::StringToNumber(config->getPort()));
	libShout->setMount(config->getMountpoint());

	libShout->setUser(config->getUsername());
	libShout->setPassword(config->getPassword());

	libShout->setFormatMp3();
	libShout->setPublic(Convert<unsigned int>::StringToNumber(config->getPublic()));
	libShout->setNonblocking(1);

	libShout->setName(config->getName());
	libShout->setUrl(config->getUrl());
	libShout->setGenre(config->getGenre());
	libShout->setDescription(config->getDescription());

	libShout->setAudioInfoBitrate(config->getBitrate());
	libShout->setAudioInfoSamplerate(config->getSamplerate());
	libShout->setAudioInfoChannels(config->getChannels());

	logSrv->info("LibShout initialized: " + shoutVersion);
}

void IcecastClient::connectShout()
{
	libShout->startShout();
}

void IcecastClient::finilizeShout()
{
	libShout->finilizeShout();
}

void IcecastClient::streamPlaylist()
{
	try
	{
		numberOfPlayedTracks = 0;

		while (playlistHandler->hasNext() && !sigSrv->gotSigInt())
		{
			PlaylistItem item = playlistHandler->nextTrack();

			string track = item.getTrack();
			string trackTitle = item.getTrackTitle();

			logNowPlaying(item);

			libShout->streamFile(track.c_str(), trackTitle.c_str());

			numberOfPlayedTracks++;
		}

		logSrv->info("Playlist finished!");
	}
	catch (DomainException& e)
	{
		logSrv->error(e.fullError());
	}
}

void IcecastClient::action()
{
	loadConfig();

	initializePlaylist();

	loadPlaylist();

	initializeShout();

	connectShout();

	streamPlaylist();

	finilizeShout();
}

void IcecastClient::nextTrack()
{
	logSrv->debug("Next Track");
}

void IcecastClient::stopPlaying()
{
	logSrv->debug("Stop Playing");
}

PlaylistItem IcecastClient::nowPlaying()
{
	return playlistHandler->getCurrentTrack();
}

int IcecastClient::remainingTrackTime()
{
	return playlistHandler->getRemainingTrackDuration();
}

string IcecastClient::getGenreStats()
{
	return playlistHandler->getGenrePercentages();
}

string IcecastClient::getArtistStats()
{
	return playlistHandler->getArtistPercentages();
}
