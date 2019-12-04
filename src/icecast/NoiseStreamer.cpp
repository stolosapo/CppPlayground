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
    NoiseStreamerHealth(),
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

	finilizeShout();
}

string NoiseStreamer::agentVersion()
{
	return string(USER_AGENT) + "/" + version();
}

NoiseStreamerConfig* NoiseStreamer::getConfig()
{
    return config;
}

void NoiseStreamer::logNowPlaying(NoiseStreamerPlaylistItem& nssItem)
{
    if (nssItem.isSuccessEncoded())
    {
        logSrv->info("Playing: " + nssItem.getTrackFile());
    }
    else
    {
        logSrv->warn("Skipping: " + nssItem.getTrack().getTrack());
    }
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
    string lameVersion = encSrv->version();
	string fullVersion = clientVersion + " " + shoutVersion + " " + lameVersion;

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
    if (libShout != NULL)
    {
        libShout->finilizeShout();
        delete libShout;
        libShout = NULL;
    }
}

string NoiseStreamer::shoutVersion()
{
    if (libShout == NULL)
    {
        throw DomainException(NoiseStreamerDomainErrorCode::NSS0025);
    }

    return libShout->shoutFullVersion();
}

string NoiseStreamer::shoutError()
{
    if (libShout == NULL)
    {
        throw DomainException(NoiseStreamerDomainErrorCode::NSS0025);
    }

    return string(libShout->getError());
}

void NoiseStreamer::streamPlaylist()
{
	try
	{
        resetErrorCounter();

		while (hasNext() && !sigSrv->gotSigInt())
		{
            checkIfErrorCounterThresholdReached();

			streamNextTrack();
		}

		logSrv->info("Playlist finished!");
	}
	catch (DomainException& e)
	{
		logSrv->error(handle(e));
	}
}

void NoiseStreamer::streamNextTrack()
{
    try
    {
        NoiseStreamerPlaylistItem* nssItem = nextTrack();

        if (!nssItem->readyToPlay())
        {
            nssItem->waitToFinishEncode();
        }

        if (!nssItem->isSuccessEncoded())
        {
            /* TODO: Should log this track as failed */
            logNowPlaying(*nssItem);
            archiveTrack(nssItem);
            return;
        }

        logNowPlaying(*nssItem);
        streamAudioFile(nssItem);
        archiveTrack(nssItem);
    }
    catch (DomainException& e)
	{
		// logSrv->error(handle(e));
        // incrementErrorCounter(); ERROR NEVER ENDING
        throw e;
	}
}

void NoiseStreamer::streamAudioFile(NoiseStreamerPlaylistItem* nssItem)
{
    const int AUDIO_SIZE = 4096;

	unsigned char buff[AUDIO_SIZE];
	long read;
    PlaylistItem item = nssItem->getTrack();

	FILE* mp3file;
    mp3file = FileHelper::openReadBinary(nssItem->getTrackFile());

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

        if (!libShout->isConnected())
        {
            string connStr = Convert<int>::NumberToString(libShout->getConnected());
            throw DomainException(NoiseStreamerDomainErrorCode::NSS0020, "Connection status '" + connStr + "'");
        }

		// cout << libShout->shoutSend(buff, read) << endl;
        libShout->shoutSend(buff, read);

        setShoutQueueLenth(libShout->shoutQueuelen());

        // if (libShout->shoutQueuelen() >= 0)
        // {
        //     string ql = Convert<int>::NumberToString(libShout->shoutQueuelen());
        //
        //     logSrv->warn("Queue Length: " + ql);
        // }

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
