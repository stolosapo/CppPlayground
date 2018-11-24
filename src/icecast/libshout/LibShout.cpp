#include <unistd.h>
#include <fstream>

#include "LibShout.h"

#include "../../kernel/di/GlobalAppContext.h"
#include "../../kernel/interruption/SignalService.h"

#include "../../kernel/converter/Convert.h"
#include "../../kernel/utils/StringHelper.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../../kernel/exception/ExceptionMapper.h"
#include "../exception/NoiseStreamerDomainErrorCode.h"
#include "../NoiseStreamer.h"


LibShout::LibShout(ILogService *logSrv, SignalService* sigSrv)
	: logSrv(logSrv), sigSrv(sigSrv)
{
	currentRetryNumber = 0;
	_retryLocker.init();
}

LibShout::~LibShout()
{
	_retryLocker.destroy();
}

bool LibShout::checkStatusAndLogOnError(string mess)
{
	bool isOk = successLastAction();

	if (!isOk)
	{
		cout << getErrno() << ". " << getError() << " -- " << mess << endl;
	}

	return isOk;
}

int LibShout::currentTries()
{
	_retryLocker.lock();
	int num = currentRetryNumber;
	_retryLocker.unlock();

	return num;
}

void LibShout::incrementTries()
{
	_retryLocker.lock();
	currentRetryNumber++;
	_retryLocker.unlock();
}

void LibShout::clearTries()
{
	_retryLocker.lock();
	currentRetryNumber = 0;
	_retryLocker.unlock();
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

	shoutNew();
}

void LibShout::startShout()
{
#ifdef ICECAST
	string server_url = "http://" + getHost() + ":" + getPort() + getMount();

	long ret = shoutOpen();
	if (ret == SHOUTERR_SUCCESS)
	{
		ret = SHOUTERR_CONNECTED;
	}

	if (ret == SHOUTERR_BUSY)
	{
		logSrv->info("Connection to [" + server_url + "] is pending...");
	}

	while (ret == SHOUTERR_BUSY && !sigSrv->gotSigInt())
	{
		usleep(10000);
		ret = getConnected();
	}

	if (ret != SHOUTERR_CONNECTED)
	{
		DomainException err(NoiseStreamerDomainErrorCode::NSS0020, getError());
		logSrv->warn(handle(err));
		restartShout();
	}
	else
	{
		logSrv->info("Connected to server: " + server_url);
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
		throw DomainException(NoiseStreamerDomainErrorCode::NSS0023);
	}
}

bool LibShout::successLastAction()
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
	return errNo == SHOUTERR_SUCCESS;
#else
	return false;
#endif
}
