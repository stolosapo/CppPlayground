#include "LibShout.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../exception/IcecastDomainErrorCode.h"
#include "../../kernel/converter/Convert.h"

void LibShout::shoutInit()
{
#ifdef ICECAST
	shout_init();
#endif
}

void LibShout::shoutShutdown()
{
#ifdef ICECAST
	shout_shutdown();
#endif
}

string LibShout::shoutVersion(int *major, int *minor, int *patch)
{
#ifdef ICECAST
	const char* version = shout_version(major, minor, patch);
	return string(version);
#else
	return "";
#endif
}

void LibShout::shoutNew()
{
#ifdef ICECAST
	if (!(shout = shout_new()))
	{
		throw DomainException(IcecastDomainErrorCode::ICS0002);
	}
#endif
}

void LibShout::shoutFree()
{
#ifdef ICECAST
	shout_free(shout);
#endif
}
