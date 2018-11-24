#include "AlsaCaptureMenuItem.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../exception/NoiseStreamerDomainErrorCode.h"

#include "../../kernel/di/GlobalAppContext.h"
#include "../../kernel/interruption/SignalService.h"

#include "../../kernel/audio/Alsa/exception/AlsaDomainErrorCode.h"
#include "../../kernel/audio/Alsa/AlsaCapture.h"


AlsaCaptureMenuItem::AlsaCaptureMenuItem(ILogService *logSrv) : MenuItem()
{
	this->logSrv = logSrv;

	this->setId(1);

	this->setName("Alsa Capture");
	this->setTitle("Alsa Capture");
}

AlsaCaptureMenuItem::~AlsaCaptureMenuItem()
{

}

void AlsaCaptureMenuItem::check()
{
#ifndef ALSA
	throw DomainException(AlsaDomainErrorCode::ALS0001);
#endif
}

void AlsaCaptureMenuItem::action()
{
	SignalService* sigSrv = inject<SignalService>("signalService");

	AlsaCapture alsa;

	alsa.capture();
}
