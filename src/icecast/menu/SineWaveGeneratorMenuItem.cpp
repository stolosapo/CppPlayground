#include "SineWaveGeneratorMenuItem.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../exception/NoiseStreamerDomainErrorCode.h"

#include "../../kernel/di/GlobalAppContext.h"
#include "../../kernel/interruption/SignalService.h"
#include "../../kernel/arguments/ArgumentService.h"
#include "../../kernel/audio/wave/generator/SineWaveGenerator.h"


SineWaveGeneratorMenuItem::SineWaveGeneratorMenuItem(ILogService *logSrv) : MenuItem()
{
	this->logSrv = logSrv;

	this->setId(3);

	this->setName("nss.sinewave.generator");
	this->setTitle("SineWave Generator");
}

SineWaveGeneratorMenuItem::~SineWaveGeneratorMenuItem()
{

}

void SineWaveGeneratorMenuItem::check()
{

}

void SineWaveGeneratorMenuItem::action()
{
    SignalService* sigSrv = inject<SignalService>("signalService");

    SineWaveGenerator generator(sigSrv);
    generator.generate();
}

// string SineWaveGeneratorMenuItem::help()
// {
//     // return "Generates sine wave audio. In order to use it must pipe the output to soundcard (e.g. | aplay)";
//     return "";
// }
