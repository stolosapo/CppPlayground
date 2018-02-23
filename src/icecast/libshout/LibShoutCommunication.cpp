#include "LibShout.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../exception/IcecastDomainErrorCode.h"
#include "../../kernel/converter/Convert.h"

int LibShout::shoutSend(const unsigned char *data, size_t len)
{
#ifdef ICECAST
	shout_send(shout, data, len);
#endif
}

int LibShout::shoutQueuelen()
{
#ifdef ICECAST
	return (int) shout_queuelen(shout);
#else
	return 0;
#endif
}

void LibShout::shoutSync()
{
#ifdef ICECAST
	shout_sync(shout);
#endif
}

int LibShout::shoutDelay()
{
#ifdef ICECAST
	return shout_delay(shout);
#else
	return 0;
#endif
}
