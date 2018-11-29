#include "NoiseStreamer.h"

#include <fstream>

#include "exception/NoiseStreamerDomainErrorCode.h"

#include "../kernel/converter/Convert.h"
#include "../kernel/utils/FileHelper.h"
#include "../kernel/exception/domain/DomainException.h"
#include "../kernel/exception/ExceptionMapper.h"
#include "../kernel/configuration/ConfigLoader.h"

#include "../kernel/di/GlobalAppContext.h"
#include "../kernel/interruption/SignalService.h"

#include "../kernel/audio/playlist/PlaylistHandlerFactory.h"


const char* NoiseStreamer::USER_AGENT = "NoiseStreamer";


NoiseStreamer::NoiseStreamer(
	ILogService *logSrv,
	SignalService *sigSrv,
	AudioTagService *tagSrv,
    AudioEncodingService *encSrv,
    string configFilename)
	: Version(1, 0, 0),
	NoiseStreamerNavigator(logSrv, sigSrv),
	logSrv(logSrv),
	sigSrv(sigSrv),
	tagSrv(tagSrv),
    encSrv(encSrv),
    configFilename(configFilename)
{
	this->config = NULL;
	this->libShout = NULL;
	playlistHandlerFactory = NULL;
	playlistHandler = NULL;

	numberOfPlayedTracks = 0;
}

NoiseStreamer::~NoiseStreamer()
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

string NoiseStreamer::agentVersion()
{
	return string(USER_AGENT) + "/" + string(version());
}

void NoiseStreamer::logNowPlaying(PlaylistItem item)
{
	string i = Convert<int>::NumberToString(item.getTrackIndex());

	logSrv->info("Index: " + i);
	logSrv->info("-- Playing: " + item.getTrack());
	logSrv->info("-- Track: " + item.getTrackTitle());
}

void NoiseStreamer::onLibShoutError(void* sender, EventArgs* e)
{
	LibShout* shout = (LibShout*) sender;

	if (!shout->isConnected())
	{
		shout->restartShout();
	}

	throw DomainException(NoiseStreamerDomainErrorCode::NSS0024);
}

int NoiseStreamer::getNumberOfPlayedTracks()
{
	return numberOfPlayedTracks;
}

void NoiseStreamer::loadConfig()
{
	ConfigLoader<NoiseStreamerConfig> loader(configFilename);

	this->config = loader.load();
}

void NoiseStreamer::initializePlaylist()
{
	string playlistFile = config->getPlaylist();
	string historyFile = config->getHistory();
	const char* metadataFile = config->getMetadata().c_str();
	PlaylistStrategyType type = config->getStrategyType();
	bool repeat = config->getRepeat();

	if (type == NONE)
	{
		throw DomainException(NoiseStreamerDomainErrorCode::NSS0022);
	}

	playlistHandlerFactory =
		new PlaylistHandlerFactory(playlistFile, historyFile, type, repeat);

	playlistHandler = playlistHandlerFactory->create();

	logSrv->info("Icecast playlist initialized!");
}

void NoiseStreamer::loadPlaylist()
{
	string playlistFile = config->getPlaylist();
	string historyFile = config->getHistory();
	playlistHandler->load();
	int size = playlistHandler->playlistSize();
	int historySize = playlistHandler->historySize();

	logSrv->info("Playlist: '" + playlistFile + "' loaded, with '" + Convert<int>::NumberToString(size) + "' tracks");
	logSrv->info("History: '" + historyFile + "' loaded, with '" + Convert<int>::NumberToString(historySize) + "' tracks");
}

void NoiseStreamer::initializeShout()
{
	libShout = new LibShout(logSrv, sigSrv);
	libShout->errorEvent += onLibShoutError;
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

void NoiseStreamer::connectShout()
{
	libShout->startShout();
}

void NoiseStreamer::finilizeShout()
{
	libShout->finilizeShout();
}

void NoiseStreamer::streamPlaylist()
{
	try
	{
		numberOfPlayedTracks = 0;

		while (playlistHandler->hasNext() && !sigSrv->gotSigInt())
		{
			waitForResume();

			PlaylistItem item = playlistHandler->nextTrack();

			string track = item.getTrack();
			string trackTitle = item.getTrackTitle();

			logNowPlaying(item);

			streamAudioFile(track.c_str(), trackTitle.c_str());

			numberOfPlayedTracks++;
		}

		logSrv->info("Playlist finished!");
	}
	catch (DomainException& e)
	{
		logSrv->error(handle(e));
	}
}

void NoiseStreamer::streamAudioFile(const char* filename, const char* trackMetadata)
{
    const int AUDIO_SIZE = 4096;
    // const int AUDIO_SIZE = 8192;

	unsigned char buff[AUDIO_SIZE];
	long read;

	FILE* mp3file;
	mp3file = fopen(filename , "rb");

	/* Update metadata */
	libShout->updateMetadata(string(trackMetadata));

	while (!sigSrv->gotSigInt() && !isGoToNext())
	{
		waitForResume();

		read = fread(buff, 1, sizeof(buff), mp3file);

		if (read <= 0)
		{
			break;
		}

		libShout->shoutSend(buff, read);

        if (libShout->shoutQueuelen() >= 0)
        {
            string ql = Convert<int>::NumberToString(libShout->shoutQueuelen());

            // logSrv->warn("Queue Length: " + ql);
        }

		libShout->shoutSync();
	}

	normal();

	fclose(mp3file);
}

void NoiseStreamer::action()
{
	loadConfig();

	initializePlaylist();

	loadPlaylist();

	initializeShout();

	connectShout();

	streamPlaylist();

	finilizeShout();
}

void NoiseStreamer::stopPlaying()
{
	logSrv->debug("Stop Playing");
}

PlaylistItem NoiseStreamer::nowPlaying()
{
	return playlistHandler->getCurrentTrack();
}

int NoiseStreamer::remainingTrackTime()
{
	return playlistHandler->getRemainingTrackDuration();
}

string NoiseStreamer::getGenreStats()
{
	return playlistHandler->getGenrePercentages();
}

string NoiseStreamer::getArtistStats()
{
	return playlistHandler->getArtistPercentages();
}