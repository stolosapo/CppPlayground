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
    ITimeService *timeSrv,
	AudioTagService *tagSrv,
    AudioEncodingService *encSrv,
    string configFilename)
	: Version(1, 0, 0),
	NoiseStreamerNavigator(logSrv, sigSrv),
    NoiseStreamerPlaylist(logSrv, timeSrv, encSrv),
	logSrv(logSrv),
	sigSrv(sigSrv),
	tagSrv(tagSrv),
    encSrv(encSrv),
    configFilename(configFilename)
{
	this->config = NULL;
	this->libShout = NULL;
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
}

string NoiseStreamer::agentVersion()
{
	return string(USER_AGENT) + "/" + string(version());
}

void NoiseStreamer::logNowPlaying(const PlaylistItem& item)
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

void NoiseStreamer::loadConfig()
{
	ConfigLoader<NoiseStreamerConfig> loader(configFilename);

	this->config = loader.load();
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
		while (hasNext() && !sigSrv->gotSigInt())
		{
			NoiseStreamerPlaylistItem* nssItem = nextTrack();

            if (!nssItem->readyToPlay())
            {
                nssItem->waitToFinishEncode();
            }

            PlaylistItem item = nssItem->getTrack();
            logNowPlaying(item);
            streamAudioFile(item);
            archiveTrack(nssItem);
		}

		logSrv->info("Playlist finished!");
	}
	catch (DomainException& e)
	{
		logSrv->error(handle(e));
	}
}

void NoiseStreamer::streamAudioFile(const PlaylistItem& item)
{
    const int AUDIO_SIZE = 4096;

	unsigned char buff[AUDIO_SIZE];
	long read;

	FILE* mp3file;
    mp3file = FileHelper::openReadBinary(item.getTrack());

	/* Update metadata */
	libShout->updateMetadata(item.getTrackTitle());

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

void NoiseStreamer::reEncodeAudioFile(PlaylistItem item)
{
    cout << "Start Decoding.." << endl;
	encSrv->decode(item.getTrack(), "audio.wav");
    cout << "End Decoding.." << endl;

    int samplerate = Convert<int>::StringToNumber(config->getSamplerate());
    AudioTag* metadata = item.getMetadata();
    metadata->setReencodeData(VBR, BR_16kbps, samplerate, 3);

    cout << "Start Re-Encoding.." << endl;
	encSrv->encode("audio.wav", "audio.mp3", metadata);
    cout << "End Re-Encoding.." << endl;
}

void NoiseStreamer::action()
{
	loadConfig();

	initializePlaylist(config);

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
