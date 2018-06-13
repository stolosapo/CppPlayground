#include "LibShout.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../exception/IcecastDomainErrorCode.h"
#include "../../kernel/converter/Convert.h"

const char* LibShout::getError()
{
#ifdef ICECAST
	return shout_get_error(shout);
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

void LibShout::raiseErrorOnFailedAction()
{
	if (successLastAction())
	{
		return;
	}

	string errNo = Convert<int>::NumberToString(getErrno());
	string errMess = "LibShout error: '" + string(getError()) + "', with code: " + errNo;

	logSrv->error(errMess);

	errorEvent.raise(this, NULL);
}
