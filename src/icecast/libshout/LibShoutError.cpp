#include "LibShout.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../exception/IcecastDomainErrorCode.h"
#include "../../kernel/converter/Convert.h"

string LibShout::getError()
{
#ifdef ICECAST
	const char* error = shout_get_error(shout);
	return string(error);
#else
	return "";
#endif
}

int LibShout::getErrno()
{
#ifdef ICECAST
	return shout_get_errno(shout);
#else
	return 0;
#endif
}
