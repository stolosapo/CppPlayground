#include <unistd.h>
#include <fstream>

#include "LibShout.h"

#include "../../lib/converter/Convert.h"
#include "../../audio/mp3/Mp3Parser.h"
#include "../IcecastProtocol.h"

LibShout::LibShout(ILogService *logSrv, IcecastClientConfig* config)
{
	this->logSrv = logSrv;
	this->config = config;
}

LibShout::~LibShout()
{

}

void LibShout::initializeShout()
{
	shoutInit();

	shoutNew();

	setAgent(string(IcecastProtocol::USER_AGENT));
	setUser(string(IcecastProtocol::USER_AGENT));

	setProtocolHttp();

	setHost(config->getHostname());

	setPort(Convert<unsigned short>::StringToNumber(config->getPort()));

	setMount(config->getMountpoint());

	setPassword(config->getPassword());

	setPublic(Convert<unsigned int>::StringToNumber(config->getPublic()));

	setName(config->getName());
	setUrl(config->getUrl());
	setGenre(config->getGenre());
	setDescription(config->getDescription());

	setAudioInfoBitrate(config->getBitrate());
	setAudioInfoSamplerate(config->getSamplerate());
	setAudioInfoChannels(config->getChannels());
	// setAudioInfoQuality()

	setFormatMp3();

	setNonblocking(1);
}

void LibShout::startShout()
{
#ifdef ICECAST
	unsigned char buff[4096];
	long read, ret, total;

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
		logSrv->error("Error connecting: " + getError());

		finilizeShout();
		return;
	}

	logSrv->info("Connected to server...");
	total = 0;

	Mp3Parser mp3Parser;
	// char* fileData = mp3Parser.loadFile("03-TakeFive.mp3");
	//
	// unsigned char* buffer = (unsigned char*) fileData;
	// if (sizeof(buffer) <= 0)
	// {
	// 	finilizeShout();
	// 	return;
	// }

	// ifstream mp3file = mp3Parser.asStream("03-TakeFive.mp3");
	FILE* mp3file;
	mp3file = fopen("03-TakeFive.mp3" , "rb");

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

#endif
}

void LibShout::finilizeShout()
{
	shoutClose();

	shoutShutdown();
}
