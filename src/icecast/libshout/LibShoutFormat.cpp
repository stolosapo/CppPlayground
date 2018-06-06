#include "LibShout.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../exception/IcecastDomainErrorCode.h"
#include "../../kernel/converter/Convert.h"

void LibShout::setFormat(unsigned int format)
{
#ifdef ICECAST
	if (shout_set_format(shout, format) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0017, getError());
	}
#endif
}

void LibShout::setFormatOgg()
{
#ifdef ICECAST
	setFormat(SHOUT_FORMAT_OGG);
#endif
}

void LibShout::setFormatMp3()
{
#ifdef ICECAST
	setFormat(SHOUT_FORMAT_MP3);
#endif
}

void LibShout::setFormatWebM()
{
#ifdef ICECAST
	setFormat(SHOUT_FORMAT_WEBM);
#endif
}

void LibShout::setFormatWebMAudio()
{
#ifdef ICECAST
	setFormat(SHOUT_FORMAT_WEBMAUDIO);
#endif
}
