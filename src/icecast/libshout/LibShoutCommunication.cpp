#include "LibShout.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../exception/IcecastDomainErrorCode.h"
#include "../../kernel/converter/Convert.h"

int LibShout::shoutSend(const unsigned char *data, size_t len)
{
#ifdef ICECAST

	if (!successLastAction())
	{
		return 0;
	}

	return shout_send(shout, data, len);
#else
	return 0;
#endif
}

int LibShout::shoutQueuelen()
{
#ifdef ICECAST

	if (!successLastAction())
	{
		return 0;
	}

	return (int) shout_queuelen(shout);
#else
	return 0;
#endif
}

void LibShout::shoutSync()
{
#ifdef ICECAST

	if (!successLastAction())
	{
		return;
	}

	shout_sync(shout);
#endif
}

int LibShout::shoutDelay()
{
#ifdef ICECAST

	if (!successLastAction())
	{
		return 0;
	}

	return shout_delay(shout);
#else
	return 0;
#endif
}
