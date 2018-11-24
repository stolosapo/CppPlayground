#include "LibShout.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../exception/NoiseStreamerDomainErrorCode.h"
#include "../../kernel/converter/Convert.h"

void LibShout::setProtocol(unsigned int protocol)
{
#ifdef ICECAST
	if (shout_set_protocol(shout, protocol) != SHOUTERR_SUCCESS)
	{
		throw DomainException(NoiseStreamerDomainErrorCode::NSS0018, getError());
	}
#endif
}

void LibShout::setProtocolHttp()
{
#ifdef ICECAST
	setProtocol(SHOUT_PROTOCOL_HTTP);
#endif
}

void LibShout::setProtocolXAudioCast()
{
#ifdef ICECAST
	setProtocol(SHOUT_PROTOCOL_XAUDIOCAST);
#endif
}

void LibShout::setProtocolIcy()
{
#ifdef ICECAST
	setProtocol(SHOUT_PROTOCOL_ICY);
#endif
}

void LibShout::setProtocolRoarAudio()
{
#ifdef ICECAST
	// setProtocol(SHOUT_PROTOCOL_ROARAUDIO);
#endif
}
