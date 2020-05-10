#include "AlsaCaptureMenuItem.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../exception/NoiseStreamerDomainErrorCode.h"

#include "../../kernel/di/GlobalAppContext.h"
#include "../../kernel/interruption/SignalService.h"
#include "../../kernel/arguments/ArgumentService.h"
#include "../../kernel/audio/alsa/AlsaCapture.h"


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

    AlsaCapture alsa;
    alsa.capture();
}
