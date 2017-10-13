#include "IcecastClient.h"

#include "config/IcecastClientConfigLoader.h"
#include "exception/IcecastDomainErrorCode.h"
#include "../audio/mp3/Mp3Parser.h"

#include "../lib/converter/Convert.h"
#include "../lib/exception/domain/DomainException.h"


IcecastClient::IcecastClient(ILogService *logSrv) : ITcpClient()
{
	this->logSrv = logSrv;
}

IcecastClient::~IcecastClient()
{
	if (protocol != NULL)
	{
		// delete protocol;
	}

	if (config != NULL)
	{
		// delete config;
	}

	if (libShout != NULL)
	{
		// delete libShout;
	}
}

void IcecastClient::loadConfig()
{
	IcecastClientConfigLoader* loader = new IcecastClientConfigLoader("icecast.config");

	this->config = loader->load();

	this->protocol = new IcecastProtocol(this->config);

	delete loader;
}

void IcecastClient::streamAudio()
{
	libShout = new LibShout(logSrv, config);

	libShout->initializeShout();

	try
	{
		libShout->startShout();

		libShout->streamFile("03-TakeFive.mp3");
		libShout->streamFile("03-TakeFive.mp3");
	}
	catch (DomainException& e)
	{
		logSrv->error(e.fullError());
	}

	libShout->finilizeShout();
}

void IcecastClient::action()
{
	loadConfig();

	streamAudio();

	return;
}
