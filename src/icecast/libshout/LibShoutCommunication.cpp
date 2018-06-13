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

	int res = shout_send(shout, data, len);

	raiseErrorOnFailedAction();

	return res;
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

	int res = (int) shout_queuelen(shout);

	raiseErrorOnFailedAction();

	return res;
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

	raiseErrorOnFailedAction();
#endif
}

int LibShout::shoutDelay()
{
#ifdef ICECAST

	if (!successLastAction())
	{
		return 0;
	}

	int res = shout_delay(shout);

	raiseErrorOnFailedAction();

	return res;
#else
	return 0;
#endif
}
