#include "LibShout.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../exception/IcecastDomainErrorCode.h"
#include "../../kernel/converter/Convert.h"

void LibShout::setAudioInfo(string name, string value)
{
#ifdef ICECAST
	if (shout_set_audio_info(shout, name.c_str(), value.c_str()) != SHOUTERR_SUCCESS)
	{
		string mess = name + ":" + value;
		throw DomainException(IcecastDomainErrorCode::ICS0014, getError());
	}
#endif
}

void LibShout::setAudioInfoBitrate(string value)
{
#ifdef ICECAST
	setAudioInfo(SHOUT_AI_BITRATE, value);
#endif
}

void LibShout::setAudioInfoSamplerate(string value)
{
#ifdef ICECAST
	setAudioInfo(SHOUT_AI_SAMPLERATE, value);
#endif
}

void LibShout::setAudioInfoChannels(string value)
{
#ifdef ICECAST
	setAudioInfo(SHOUT_AI_CHANNELS, value);
#endif
}

void LibShout::setAudioInfoQuality(string value)
{
#ifdef ICECAST
	setAudioInfo(SHOUT_AI_QUALITY, value);
#endif
}
