#include "AlsaCaptureMenuItem.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../exception/NoiseStreamerDomainErrorCode.h"

#include "../../kernel/di/GlobalAppContext.h"
#include "../../kernel/interruption/SignalService.h"
#include "../../kernel/arguments/ArgumentService.h"
#include "../../kernel/audio/alsa/AlsaAudioSource.h"


AlsaCaptureMenuItem::AlsaCaptureMenuItem(ILogService *logSrv) : MenuItem()
{
	this->logSrv = logSrv;

	this->setId(4);

	this->setName("nss.alsa.capture");
	this->setTitle("Alsa Capture");
}

AlsaCaptureMenuItem::~AlsaCaptureMenuItem()
{

}

void AlsaCaptureMenuItem::check()
{

}

void AlsaCaptureMenuItem::action()
{
    SignalService* sigSrv = inject<SignalService>("signalService");

    AlsaConfig *config = new AlsaConfig(
        "hw:0,0",
        44100,
        2,
        "SND_PCM_FORMAT_S16_LE",
        128);

    AlsaAudioSource alsa(config);
    alsa.capture();

    delete config;
}
