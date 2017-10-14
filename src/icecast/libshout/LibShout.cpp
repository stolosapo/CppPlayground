#include <unistd.h>
#include <fstream>

#include "LibShout.h"

#include "../../lib/converter/Convert.h"
#include "../../audio/mp3/Mp3Parser.h"
#include "../IcecastProtocol.h"

#include "../../lib/exception/domain/DomainException.h"
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

	shoutNew();

	setAgent(string(IcecastProtocol::USER_AGENT));

	setProtocolHttp();

	setHost(config->getHostname());
	setPort(Convert<unsigned short>::StringToNumber(config->getPort()));
	setMount(config->getMountpoint());
	setUser("source");
	setPassword(config->getPassword());

	setFormatMp3();
	setPublic(Convert<unsigned int>::StringToNumber(config->getPublic()));
	setNonblocking(1);

	setName(config->getName());
	setUrl(config->getUrl());
	setGenre(config->getGenre());
	setDescription(config->getDescription());

	setMetaName(config->getName());
	setMetaUrl(config->getUrl());
	setMetaGenre(config->getGenre());
	setMetaDescription(config->getDescription());
	setMeta();

	setAudioInfoBitrate(config->getBitrate());
	setAudioInfoSamplerate(config->getSamplerate());
	setAudioInfoChannels(config->getChannels());
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

	while (1)
	{
		read = fread(buff, 1, sizeof(buff), mp3file);
		total = total + read;

		if (read > 0)
		{
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

	fclose(mp3file);
#endif
}