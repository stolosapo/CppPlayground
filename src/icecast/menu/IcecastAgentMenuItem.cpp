#include "IcecastAgentMenuItem.h"

#include "../IcecastAgent.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../exception/IcecastDomainErrorCode.h"

#include "../../kernel/di/GlobalAppContext.h"
#include "../../kernel/interruption/SignalService.h"
#include "../../kernel/audio/AudioTagService.h"
#include "../../kernel/audio/encoding/AudioEncodingService.h"
#include "../../kernel/time/ITimeService.h"
#include "../../kernel/arguments/ArgumentService.h"


IcecastAgentMenuItem::IcecastAgentMenuItem(ILogService *logSrv) : MenuItem()
{
	this->logSrv = logSrv;

	this->setId(3);

	this->setName("Icecast Agent");
	this->setTitle("Icecast Agent");
}

IcecastAgentMenuItem::~IcecastAgentMenuItem()
{

}

void IcecastAgentMenuItem::check()
{
#ifndef ICECAST
	throw DomainException(IcecastDomainErrorCode::ICS0001);
#endif
}

void IcecastAgentMenuItem::action()
{
	SignalService* sigSrv = inject<SignalService>("signalService");
	AudioTagService* tagSrv = inject<AudioTagService>("audioTagService");
	AudioEncodingService* encSrv = inject<AudioEncodingService>("audioEncodingService");
	ITimeService* timeSrv = inject<ITimeService>("timeService");
	ArgumentService* argSrv = inject<ArgumentService>("argService");

	IcecastAgent agent(this->logSrv, sigSrv, timeSrv, tagSrv, argSrv, encSrv);

	agent.action();
}
