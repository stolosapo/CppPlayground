#include <unistd.h>
#include <fstream>

#include "LibShout.h"

#include "../../kernel/di/GlobalAppContext.h"
#include "../../kernel/interruption/SignalService.h"

#include "../../kernel/converter/Convert.h"
#include "../../audio/mp3/Mp3Parser.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../exception/IcecastDomainErrorCode.h"
#include "../IcecastClient.h"

#include "../../audio/mp3/Mp3Id3v1.h"


LibShout::LibShout(ILogService *logSrv, SignalService* sigSrv, IcecastClientConfig* config) : logSrv(logSrv), sigSrv(sigSrv), config(config)
{

}

LibShout::~LibShout()
{

}

void LibShout::finilizeShout()
{
	shoutClose();

	shoutShutdown();

	shoutFree();
}

void LibShout::initializeShout()
{
	shoutInit();
	logSrv->trace("Inited");

	shoutNew();
	logSrv->trace("Created New");

	int major;
	int minor;
	int patch;
	string version = shoutVersion(&major, &minor, &patch);
	logSrv->info("LibShout Version: " + version);

	string shoutVersion = "libshout/" + version;
	string clientVersion = IcecastClient::agentVersion();

	setAgent(clientVersion + " " + shoutVersion);
	logSrv->trace("Set Agent");

	setProtocolHttp();
	logSrv->trace("Set Protocol Http");

	setHost(config->getHostname());
	logSrv->trace("Set Host");

	setPort(Convert<unsigned short>::StringToNumber(config->getPort()));
	logSrv->trace("Set Port");

	setMount(config->getMountpoint());
	logSrv->trace("Set Mountpoint");

	setUser(config->getUsername());
	logSrv->trace("Set User '" + config->getUsername() + "'");

	setPassword(config->getPassword());
	logSrv->trace("Set Password '" + config->getPassword() + "'");

	setFormatMp3();
	logSrv->trace("Set Format Mp3");

	setPublic(Convert<unsigned int>::StringToNumber(config->getPublic()));
	logSrv->trace("Set Public");

	setNonblocking(1);
	logSrv->trace("Set Non-Blocking");

	setName(config->getName());
	logSrv->trace("Set Name");

	setUrl(config->getUrl());
	logSrv->trace("Set Url");

	setGenre(config->getGenre());
	logSrv->trace("Set Genre");

	setDescription(config->getDescription());
	logSrv->trace("Set Description");


	setMetaName(config->getName());
	logSrv->trace("Set MetaName");

	setMetaUrl(config->getUrl());
	logSrv->trace("Set MetaUrl");

	setMetaGenre(config->getGenre());
	logSrv->trace("Set MetaGenre");

	setMetaDescription(config->getDescription());
	logSrv->trace("Set MetaDescription");

	// setMeta();
	// logSrv->trace("Set Meta");


	setAudioInfoBitrate(config->getBitrate());
	logSrv->trace("Set AudioInfoBitrate");

	setAudioInfoSamplerate(config->getSamplerate());
	logSrv->trace("Set AudioInfoSamplerate");

	setAudioInfoChannels(config->getChannels());
	logSrv->trace("Set AudioInfoChannels");

	// setAudioInfoQuality()
}

void LibShout::startShout()
{
#ifdef ICECAST
	long ret;

	ret = shoutOpen();
	if (ret == SHOUTERR_SUCCESS)
	{
		ret = SHOUTERR_CONNECTED;
	}

	if (ret == SHOUTERR_BUSY)
	{
		logSrv->info("Connection pending...");
	}

	while (ret == SHOUTERR_BUSY)
	{
		usleep(10000);
		ret = getConnected();
	}

	if (ret != SHOUTERR_CONNECTED)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0020, getError());
	}

	logSrv->info("Connected to server...");
#endif
}

void LibShout::streamFile(const char* filename)
{
#ifdef ICECAST
	unsigned char buff[4096];
	long read, ret;

	FILE* mp3file;
	mp3file = fopen(filename , "rb");

	Mp3Id3v1 mp3Tag;

	mp3Tag.load(filename);

	string trackMetadata;

	if (mp3Tag.isCorrectVersion())
	{
		trackMetadata = mp3Tag.getArtist() + " - " + mp3Tag.getTitle();
	}
	else
	{
		trackMetadata = string(filename);
	}

	logSrv->info("Playing: " + string(filename));


	/* Update metadata */
	shout_metadata_t* newMetadata;
	newMetadata = createNewMetadata();
	setMetaSong(newMetadata, trackMetadata);
	setMeta(newMetadata);

	while (!sigSrv->gotSigInt())
	{

		read = fread(buff, 1, sizeof(buff), mp3file);

		if (read <= 0)
		{
			break;			
		}

		ret = shoutSend(buff, read);

		if (ret != SHOUTERR_SUCCESS)
		{
			logSrv->error("Send error: " + getError());
			break;
		}

		if (shoutQueuelen() > 0)
		{
			// logSrv->debug("Queue length: " + Convert<int>::NumberToString(shoutQueuelen()));
			// usleep(50000);
		}

		shoutSync();
	}

	freeMetadate(newMetadata);

	fclose(mp3file);
#endif
}
