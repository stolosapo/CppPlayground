#include "IcecastClientMenuItem.h"

#include "../IcecastClient.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../exception/IcecastDomainErrorCode.h"

#include "../../kernel/di/GlobalAppContext.h"
#include "../../kernel/interruption/SignalService.h"
#include "../../kernel/audio/AudioTagService.h"
#include "../../kernel/audio/encoding/AudioEncodingService.h"


IcecastClientMenuItem::IcecastClientMenuItem(ILogService *logSrv) : MenuItem()
{
	this->logSrv = logSrv;

	this->setId(1);

	this->setName("Icecast Client");
	this->setTitle("Icecast Client");
}

IcecastClientMenuItem::~IcecastClientMenuItem()
{

}

void IcecastClientMenuItem::check()
{
#ifndef ICECAST
	throw DomainException(IcecastDomainErrorCode::ICS0001);
#endif
}

void IcecastClientMenuItem::action()
{
	SignalService* sigSrv = inject<SignalService>("signalService");
	AudioTagService* tagSrv = inject<AudioTagService>("audioTagService");
    AudioEncodingService* encSrv = inject<AudioEncodingService>("audioEncodingService");

	IcecastClient* client = new IcecastClient(this->logSrv, sigSrv, tagSrv, encSrv);

	client->action();

	delete client;
}
