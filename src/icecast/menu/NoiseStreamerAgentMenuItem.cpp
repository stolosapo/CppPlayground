#include "NoiseStreamerAgentMenuItem.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../exception/NoiseStreamerDomainErrorCode.h"

#include "../../kernel/di/GlobalAppContext.h"
#include "../../kernel/interruption/SignalService.h"
#include "../../kernel/audio/AudioTagService.h"
#include "../../kernel/audio/encoding/AudioEncodingService.h"
#include "../../kernel/time/ITimeService.h"
#include "../../kernel/arguments/ArgumentService.h"


NoiseStreamerAgentMenuItem::NoiseStreamerAgentMenuItem(ILogService *logSrv) : MenuItem()
{
	this->logSrv = logSrv;

	this->setId(2);

	this->setName("Icecast Agent");
	this->setTitle("Icecast Agent");
}

NoiseStreamerAgentMenuItem::~NoiseStreamerAgentMenuItem()
{

}

void NoiseStreamerAgentMenuItem::check()
{
#ifndef ICECAST
	throw DomainException(NoiseStreamerDomainErrorCode::ICS0001);
#endif
}

NoiseStreamerAgent* NoiseStreamerAgentMenuItem::agentFactory()
{
    SignalService* sigSrv = inject<SignalService>("signalService");
	AudioTagService* tagSrv = inject<AudioTagService>("audioTagService");
	AudioEncodingService* encSrv = inject<AudioEncodingService>("audioEncodingService");
	ITimeService* timeSrv = inject<ITimeService>("timeService");
	ArgumentService* argSrv = inject<ArgumentService>("argService");

	NoiseStreamerAgent* agent = new NoiseStreamerAgent(this->logSrv, sigSrv, timeSrv, tagSrv, argSrv, encSrv);

    return agent;
}

void NoiseStreamerAgentMenuItem::action()
{
	NoiseStreamerAgent* agent = agentFactory();

	agent->action();

    delete agent;
}

string NoiseStreamerAgentMenuItem::help()
{
    NoiseStreamerAgent* agent = agentFactory();

    agent->registerArguments();
    string hh = agent->help();

    delete agent;

    return hh;
}
