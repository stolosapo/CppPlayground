#include "IcecastAgentClientMenuItem.h"

#include "../IcecastAgentClient.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../exception/IcecastDomainErrorCode.h"

#include "../../kernel/di/GlobalAppContext.h"
#include "../../kernel/interruption/SignalService.h"
#include "../../kernel/audio/AudioTagService.h"


IcecastAgentClientMenuItem::IcecastAgentClientMenuItem(ILogService *logSrv) : MenuItem()
{
	this->logSrv = logSrv;

	this->setId(3);

	this->setName("Icecast Agent Client");
	this->setTitle("Icecast Agent Client");
}

IcecastAgentClientMenuItem::~IcecastAgentClientMenuItem()
{

}

void IcecastAgentClientMenuItem::check()
{
#ifndef ICECAST
	throw DomainException(IcecastDomainErrorCode::ICS0001);
#endif
}

void IcecastAgentClientMenuItem::action()
{
	SignalService* sigSrv = inject<SignalService>("signalService");
	AudioTagService* tagSrv = inject<AudioTagService>("audioTagService");

	IcecastAgentClient client(this->logSrv, sigSrv);

	client.action();
}
