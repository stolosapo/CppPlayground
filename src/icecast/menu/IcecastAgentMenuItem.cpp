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

	this->setId(2);

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

IcecastAgent* IcecastAgentMenuItem::agentFactory()
{
    SignalService* sigSrv = inject<SignalService>("signalService");
	AudioTagService* tagSrv = inject<AudioTagService>("audioTagService");
	AudioEncodingService* encSrv = inject<AudioEncodingService>("audioEncodingService");
	ITimeService* timeSrv = inject<ITimeService>("timeService");
	ArgumentService* argSrv = inject<ArgumentService>("argService");

	IcecastAgent* agent = new IcecastAgent(this->logSrv, sigSrv, timeSrv, tagSrv, argSrv, encSrv);

    return agent;
}

void IcecastAgentMenuItem::action()
{
	IcecastAgent* agent = agentFactory();

	agent->action();

    delete agent;
}

string IcecastAgentMenuItem::help()
{
    IcecastAgent* agent = agentFactory();

    agent->registerArguments();
    string hh = agent->help();

    delete agent;

    return hh;
}
