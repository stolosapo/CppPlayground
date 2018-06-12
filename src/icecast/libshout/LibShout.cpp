#include <unistd.h>
#include <fstream>

#include "LibShout.h"

#include "../../kernel/di/GlobalAppContext.h"
#include "../../kernel/interruption/SignalService.h"

#include "../../kernel/converter/Convert.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../../kernel/exception/ExceptionMapper.h"
#include "../exception/IcecastDomainErrorCode.h"
#include "../IcecastClient.h"

#include "../../audio/mp3/Mp3Id3v1.h"


LibShout::LibShout(ILogService *logSrv, SignalService* sigSrv, IcecastClientConfig* config) : logSrv(logSrv), sigSrv(sigSrv), config(config)
{
	currentRetryNumber = 0;
}

LibShout::~LibShout()
{

}

void LibShout::logCurrentStatus(string mess)
{
	int errNo = getErrno();

	/*
	SHOUTERR_SUCCESS		(0) /* No error
	SHOUTERR_INSANE			(-1) /* Nonsensical arguments e.g. self being NULL
	SHOUTERR_NOCONNECT		(-2) /* Couldn't connect
	SHOUTERR_NOLOGIN		(-3) /* Login failed
	SHOUTERR_SOCKET			(-4) /* Socket error
	SHOUTERR_MALLOC			(-5) /* Out of memory
	SHOUTERR_METADATA		(-6)
	SHOUTERR_CONNECTED		(-7) /* Cannot set parameter while connected
	SHOUTERR_UNCONNECTED		(-8) /* Not connected
	SHOUTERR_UNSUPPORTED		(-9) /* This libshout doesn't support the requested option
	SHOUTERR_BUSY			(-10) /* Socket is busy
	SHOUTERR_NOTLS                  (-11) /* TLS requested but not supported by peer
	SHOUTERR_TLSBADCERT             (-12) /* TLS connection can not be established because of bad certificate
	SHOUTERR_RETRY                  (-13) /* Retry last operation.
	*/
#ifdef ICECAST
	switch (errNo) {

		case SHOUTERR_SUCCESS:
			// logSrv->trace("SHOUTERR_SUCCESS");
			break;
		case SHOUTERR_INSANE:
			logSrv->trace(mess + " SHOUTERR_INSANE");
			break;
		case SHOUTERR_NOCONNECT:
			logSrv->trace(mess + " SHOUTERR_NOCONNECT");
			break;
		case SHOUTERR_NOLOGIN:
			logSrv->trace(mess + " SHOUTERR_NOLOGIN");
			break;
		case SHOUTERR_SOCKET:
			logSrv->trace(mess + " SHOUTERR_SOCKET");
			break;
		case SHOUTERR_MALLOC:
			logSrv->trace(mess + " SHOUTERR_MALLOC");
			break;
		case SHOUTERR_METADATA:
			logSrv->trace(mess + " SHOUTERR_METADATA");
			break;
		case SHOUTERR_CONNECTED:
			logSrv->trace(mess + " SHOUTERR_CONNECTED");
			break;
		case SHOUTERR_UNCONNECTED:
			logSrv->trace(mess + " SHOUTERR_UNCONNECTED");
			break;
		case SHOUTERR_UNSUPPORTED:
			logSrv->trace(mess + " SHOUTERR_UNSUPPORTED");
			break;
		case SHOUTERR_BUSY:
			logSrv->trace(mess + " SHOUTERR_BUSY");
			break;
		case SHOUTERR_NOTLS:
			logSrv->trace(mess + " SHOUTERR_NOTLS");
			break;
		case SHOUTERR_TLSBADCERT:
			logSrv->trace(mess + " SHOUTERR_TLSBADCERT");
			break;
		case SHOUTERR_RETRY:
			logSrv->trace(mess + " SHOUTERR_RETRY");
			break;
		default:
			// logSrv->trace("Invalid errNo: ");
			cerr << "Invalid errNo: " << errNo << endl;
			break;
	}
#endif
}

int LibShout::currentTries()
{
	return currentRetryNumber;
}

void LibShout::incrementTries()
{
	currentRetryNumber++;
}

void LibShout::clearTries()
{
	currentRetryNumber = 0;
}

bool LibShout::maxTriesReached()
{
	return currentTries() >= MAX_RETRY_NUMBER;
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
	long ret = shoutOpen();
	if (ret == SHOUTERR_SUCCESS)
	{
		ret = SHOUTERR_CONNECTED;
	}

	if (ret == SHOUTERR_BUSY)
	{
		logSrv->info("Connection pending...");
	}

	while (ret == SHOUTERR_BUSY && !sigSrv->gotSigInt())
	{
		usleep(10000);
		ret = getConnected();
	}

	if (ret != SHOUTERR_CONNECTED)
	{
		DomainException err(IcecastDomainErrorCode::ICS0020, getError());
		logSrv->warn(handle(err));
		restartShout();
	}
	else
	{
		logSrv->info("Connected to server...");
	}
#endif
}

void LibShout::restartShout()
{
	if (isConnected())
	{
		return;
	}

	while (!maxTriesReached() && !isConnected() && !sigSrv->gotSigInt())
	{
		incrementTries();

		string times = Convert<int>::NumberToString(currentTries());
		logSrv->info("Try to reconnect... (" + times + ")");
		startShout();
	}

	if (isConnected())
	{
		clearTries();
	}

	if (maxTriesReached())
	{
		clearTries();
		throw DomainException(IcecastDomainErrorCode::ICS0023);
	}
}

void LibShout::streamFile(const char* filename, const char* trackMetadata)
{
#ifdef ICECAST
	unsigned char buff[4096];
	long read, ret;

	FILE* mp3file;
	mp3file = fopen(filename , "rb");

	/* Update metadata */
	shout_metadata_t* newMetadata = createNewMetadata();
	addMetaSong(newMetadata, string(trackMetadata));
	setMeta(newMetadata);

	logCurrentStatus("After update metedata:");

	while (!sigSrv->gotSigInt())
	{

		read = fread(buff, 1, sizeof(buff), mp3file);

		if (read <= 0)
		{
			break;
		}

		ret = shoutSend(buff, read);

		logCurrentStatus("After shoutSend:");

		if (ret != SHOUTERR_SUCCESS)
		{
			logSrv->error("Send error: " + string(getError()));
			break;
		}

		if (shoutQueuelen() > 0)
		{
			logCurrentStatus("After shoutQueuelen:");
			// logSrv->debug("Queue length: " + Convert<int>::NumberToString(shoutQueuelen()));
			// usleep(50000);
		}

		shoutSync();

		logCurrentStatus("After shoutSync:");
	}

	freeMetadata(newMetadata);
	logCurrentStatus("After freeMetadata:");

	fclose(mp3file);
#endif
}
