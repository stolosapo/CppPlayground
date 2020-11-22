#include "NoiseStreamer.h"

#include <fstream>

#include "exception/NoiseStreamerDomainErrorCode.h"

#include "audio/PlaylistAudioSource.h"
#include "audio/AudioMetadataChangedEventHandler.h"
#include "audio/ErrorAppearedEventHandler.h"

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
    NoiseStreamerHealth(),
    logSrv(logSrv),
    sigSrv(sigSrv),
    timeSrv(timeSrv),
    tagSrv(tagSrv),
    encSrv(encSrv),
    configFilename(configFilename)
{
    this->config = NULL;
    this->libShout = NULL;
    this->audioSource = NULL;
    this->audioMetadataChangedEventHandler = NULL;
    this->errorAppearedEventHandler = NULL;
}

NoiseStreamer::~NoiseStreamer()
{
    if (config != NULL)
    {
        delete config;
    }

    finilizeShout();

    if (audioSource != NULL)
    {
        delete audioSource;
    }

    if (audioMetadataChangedEventHandler != NULL)
    {
        delete audioMetadataChangedEventHandler;
    }

    if (errorAppearedEventHandler != NULL)
    {
        delete errorAppearedEventHandler;
    }
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

AudioSource* NoiseStreamer::createNewAudioSource()
{
    return new PlaylistAudioSource(
        logSrv,
        sigSrv,
        timeSrv,
        encSrv);
}

void NoiseStreamer::initializeAudioSource()
{
    if (audioSource != NULL)
    {
        delete audioSource;
    }

    audioMetadataChangedEventHandler =
        new AudioMetadataChangedEventHandler(logSrv, this);

    errorAppearedEventHandler =
        new ErrorAppearedEventHandler(this);

    audioSource = createNewAudioSource();
    audioSource->audioMetadataChanged += audioMetadataChangedEventHandler;
    audioSource->errorAppeared += errorAppearedEventHandler;

    audioSource->initialize(config);
}

void NoiseStreamer::updateAudioMetadata(string metadata)
{
    if (libShout == NULL)
    {
        logSrv->warn("Trying to update metadata on NULL libshout");
        return;
    }

    libShout->updateMetadata(metadata);
    logSrv->trace("libshout audio metadata updated: " + metadata);
}

void NoiseStreamer::streamAudioSource()
{
    const int AUDIO_SIZE = 4096;

    unsigned char buff[AUDIO_SIZE];
    long read;

    while (!sigSrv->gotSigInt())
    {
        checkIfErrorCounterThresholdReached();

        read = audioSource->readNextMp3Data(buff);

        if (read <= 0)
        {
            break;
        }

        if (!libShout->isConnected())
        {
            string connStr = Convert<int>::NumberToString(libShout->getConnected());
            throw DomainException(NoiseStreamerDomainErrorCode::NSS0020, "Connection status '" + connStr + "'");
        }

        libShout->shoutSend(buff, read);

        setShoutQueueLenth(libShout->shoutQueuelen());
        checkIfShoutQueueLengthThresholdReached();

        libShout->shoutSync();
    }
}

// void NoiseStreamer::streamPlaylist()
// {
// 	try
// 	{
//         resetErrorCounter();

// 		while (hasNext() && !sigSrv->gotSigInt() && !isStoped())
// 		{
//             checkIfErrorCounterThresholdReached();

// 			streamNextTrack();
// 		}

// 		logSrv->info("Playlist finished!");
// 	}
// 	catch (DomainException& e)
// 	{
// 		logSrv->error(handle(e));
// 	}
// }

// void NoiseStreamer::streamNextTrack()
// {
//     try
//     {
//         NoiseStreamerPlaylistItem* nssItem = nextTrack();

//         if (!nssItem->readyToPlay())
//         {
//             nssItem->waitToFinishEncode();
//         }

//         if (!nssItem->isSuccessEncoded())
//         {
//             /* TODO: Should log this track as failed */
//             logNowPlaying(*nssItem);
//             archiveTrack(nssItem);
//             return;
//         }

//         logNowPlaying(*nssItem);
//         streamAudioFile(nssItem);
//         archiveTrack(nssItem);
//     }
//     catch (DomainException& e)
// 	{
// 		// logSrv->error(handle(e));
//         // incrementErrorCounter(); ERROR NEVER ENDING
//         throw e;
// 	}
// }

// void NoiseStreamer::streamAudioFile(NoiseStreamerPlaylistItem* nssItem)
// {
//     const int AUDIO_SIZE = 4096;

// 	unsigned char buff[AUDIO_SIZE];
// 	long read;
//     PlaylistItem item = nssItem->getTrack();

// 	FILE* mp3file;
//     mp3file = FileHelper::openReadBinary(nssItem->getTrackFile());

// 	/* Update metadata */
// 	libShout->updateMetadata(item.getTrackTitle());

// 	while (!sigSrv->gotSigInt() && !isGoToNext() && !isStoped())
// 	{
// 		waitForResume();

// 		read = fread(buff, 1, sizeof(buff), mp3file);

// 		if (read <= 0)
// 		{
// 			break;
// 		}

//         if (!libShout->isConnected())
//         {
//             string connStr = Convert<int>::NumberToString(libShout->getConnected());
//             throw DomainException(NoiseStreamerDomainErrorCode::NSS0020, "Connection status '" + connStr + "'");
//         }

//         libShout->shoutSend(buff, read);

//         setShoutQueueLenth(libShout->shoutQueuelen());
//         checkIfShoutQueueLengthThresholdReached();

// 		libShout->shoutSync();
// 	}

//     if (!isStoped())
//     {
//         normal();
//     }

// 	fclose(mp3file);
// }

void NoiseStreamer::initialize()
{
    loadConfig();

    initializeAudioSource();
}

void NoiseStreamer::connect()
{
    initializeShout();

    connectShout();
}

void NoiseStreamer::disconnect()
{
    finilizeShout();
}

void NoiseStreamer::stream()
{
    try
    {
        resetErrorCounter();

        streamAudioSource();
    }
    catch(DomainException& e)
    {
        logSrv->error(handle(e));
    }
}

void NoiseStreamer::action()
{
    /* Load Config, initialize and load Playlist */
    initialize();

    /* Initialize and connect to Shout */
    connect();

    /* Stream Playlist */
    stream();

    /* Finilize Shout */
    disconnect();

    /* Shout down audio source */
    audioSource->shutdown();
}

void NoiseStreamer::shutdownStreamer()
{
    audioSource->shutdownAudioSource();
}

AudioSource* NoiseStreamer::getAudioSource()
{
    return audioSource;
}
