#include <unistd.h>
#include <fstream>

#include "LibShout.h"

#include "../../kernel/converter/Convert.h"
#include "../../audio/mp3/Mp3Parser.h"
#include "../IcecastProtocol.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../exception/IcecastDomainErrorCode.h"

LibShout::LibShout(ILogService *logSrv, IcecastClientConfig* config)
{
	this->logSrv = logSrv;
	this->config = config;
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

	setAgent(string(IcecastProtocol::USER_AGENT));
	logSrv->trace("Set Agent");

	setProtocolHttp();
	logSrv->trace("Set Protocol Http");

	setHost(config->getHostname());
	logSrv->trace("Set Host");

	setPort(Convert<unsigned short>::StringToNumber(config->getPort()));
	logSrv->trace("Set Port");

	setMount(config->getMountpoint());
	logSrv->trace("Set Mountpoint");

	setUser("source");
	logSrv->trace("Set User");

	setPassword(config->getPassword());
	logSrv->trace("Set Password");

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
	long read, ret, total;

	FILE* mp3file;
	mp3file = fopen(filename , "rb");

	logSrv->info("Playing: " + string(filename));


	/* Update metadata */
	shout_metadata_t* newMetadata;
	newMetadata = createNewMetadata();
	setMetaSong(newMetadata, string(filename));

	while (1)
	{
		read = fread(buff, 1, sizeof(buff), mp3file);
		total = total + read;

		if (read > 0)
		{

			setMeta(newMetadata);

			ret = shoutSend(buff, read);

			if (ret != SHOUTERR_SUCCESS)
			{
				logSrv->error("Send error: " + getError());
				break;
			}

			if (shoutQueuelen() > 0)
			{
				logSrv->debug("Queue length: " + Convert<int>::NumberToString(shoutQueuelen()));
			}
		}
		else
		{
			break;
		}

		shoutSync();
	}

	freeMetadate(newMetadata);

	fclose(mp3file);
#endif
}
