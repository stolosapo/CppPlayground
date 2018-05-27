#include "IcecastAgentMenuItem.h"

#include "../IcecastAgent.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../exception/IcecastDomainErrorCode.h"

#include "../../kernel/di/GlobalAppContext.h"
#include "../../kernel/interruption/SignalService.h"
#include "../../kernel/audio/AudioTagService.h"
#include "../../kernel/time/ITimeService.h"


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
	ITimeService* timeSrv = inject<ITimeService>("timeService");

	IcecastAgent agent(this->logSrv, sigSrv, timeSrv, tagSrv);

	agent.action();
}
