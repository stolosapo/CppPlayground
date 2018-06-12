#include "LibShout.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../exception/IcecastDomainErrorCode.h"
#include "../../kernel/converter/Convert.h"

int LibShout::shoutOpen()
{
#ifdef ICECAST
	return shout_open(shout);
#else
	return 0;
#endif
}

int LibShout::shoutClose()
{
#ifdef ICECAST
	return shout_close(shout);
#else
	return 0;
#endif
}

/* returns SHOUTERR_CONNECTED or SHOUTERR_UNCONNECTED */
int LibShout::getConnected()
{
#ifdef ICECAST
	return shout_get_connected(shout);
#else
	return -8;
#endif
}

bool LibShout::isConnected()
{
#ifdef ICECAST
	return getConnected() == SHOUTERR_CONNECTED;
#else
	return false;;
#endif
}

void LibShout::setHost(string host)
{
#ifdef ICECAST
	if (shout_set_host(shout, host.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0003, getError());
	}
#endif
}

string LibShout::getHost()
{
#ifdef ICECAST
	return string(shout_get_host(shout));
#else
	return "";
#endif
}

void LibShout::setPort(unsigned short port)
{
#ifdef ICECAST
	if (shout_set_port(shout, port) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0004, getError());
	}
#endif
}

string LibShout::getPort()
{
#ifdef ICECAST
	return Convert<unsigned short>::NumberToString(shout_get_port(shout));
#else
	return "";
#endif
}

void LibShout::setUser(string username)
{
#ifdef ICECAST
	if (shout_set_user(shout, username.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0006, getError());
	}
#endif
}

void LibShout::setPassword(string password)
{
#ifdef ICECAST
	if (shout_set_password(shout, password.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0007, getError());
	}
#endif
}

void LibShout::setMount(string mount)
{
#ifdef ICECAST
	if (shout_set_mount(shout, mount.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0008, getError());
	}
#endif
}

string LibShout::getMount()
{
#ifdef ICECAST
	return string(shout_get_mount(shout));
#else
	return "";
#endif
}
