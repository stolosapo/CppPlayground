#include "LibShout.h"

#include "../../lib/exception/domain/DomainException.h"
#include "../exception/IcecastDomainErrorCode.h"

void LibShout::shoutInit()
{
#ifdef ICECAST
	shout_init();
	logSrv->info("Shout Init");
#endif
}

void LibShout::shoutShutdown()
{
#ifdef ICECAST
	shout_shutdown();
	logSrv->info("Shout Shutdown");
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

	logSrv->info("Shout allocated");
#endif
}

void LibShout::shoutFree()
{
#ifdef ICECAST
	shout_free(shout);
#endif
}

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

/* returns SHOUTERR_CONNECTED or SHOUTERR_UNCONNECTED */
int LibShout::getConnected()
{
#ifdef ICECAST
	return shout_get_connected(shout);
#else
	return -8;
#endif
}

void LibShout::setHost(string host)
{
#ifdef ICECAST
	if (shout_set_host(shout, host.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0003);
	}

	logSrv->info("Shout hostname set");
#endif
}

void LibShout::setPort(unsigned short port)
{
#ifdef ICECAST
	if (shout_set_port(shout, port) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0004);
	}

	logSrv->info("Shout port set");
#endif
}

void LibShout::setAgent(string agent)
{
#ifdef ICECAST
	if (shout_set_agent(shout, agent.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0005);
	}

	logSrv->info("Shout agent set");
#endif
}

void LibShout::setUser(string username)
{
#ifdef ICECAST
	if (shout_set_user(shout, username.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0006);
	}

	logSrv->info("Shout username set");
#endif
}

void LibShout::setPassword(string password)
{
#ifdef ICECAST
	if (shout_set_password(shout, password.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0007);
	}

	logSrv->info("Shout password set");
#endif
}

void LibShout::setMount(string mount)
{
#ifdef ICECAST
	if (shout_set_mount(shout, mount.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0008);
	}

	logSrv->info("Shout mountpoint set");
#endif
}

void LibShout::setName(string name)
{
#ifdef ICECAST
	if (shout_set_name(shout, name.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0009);
	}

	logSrv->info("Shout name set");
#endif
}

void LibShout::setUrl(string url)
{
#ifdef ICECAST
	if (shout_set_url(shout, url.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0010);
	}

	logSrv->info("Shout url set");
#endif
}

void LibShout::setGenre(string genre)
{
#ifdef ICECAST
	if (shout_set_genre(shout, genre.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0011);
	}

	logSrv->info("Shout genre set");
#endif
}

void LibShout::setDescription(string description)
{
#ifdef ICECAST
	if (shout_set_description(shout, description.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0012);
	}

	logSrv->info("Shout description set");
#endif
}

void LibShout::setDumpfile(string dumpfile)
{
#ifdef ICECAST
	if (shout_set_dumpfile(shout, dumpfile.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0013);
	}

	logSrv->info("Shout dumpfile set");
#endif
}

void LibShout::setAudioInfo(string name, string value)
{
#ifdef ICECAST
	if (shout_set_audio_info(shout, name.c_str(), value.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0014);
	}

	logSrv->info("Shout audio data set");
#endif
}

void LibShout::setMeta(string name, string value)
{
#ifdef ICECAST
	// if (shout_set_meta(shout, name.c_str(), value.c_str()) != SHOUTERR_SUCCESS)
	// {
	// 	throw DomainException(IcecastDomainErrorCode::ICS0015);
	// }
	//
	// logSrv->info("Shout metadata set");
#endif
}

void LibShout::setPublic(unsigned int make_public)
{
#ifdef ICECAST
	if (shout_set_public(shout, make_public) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0016);
	}

	logSrv->info("Shout public set");
#endif
}

void LibShout::setFormat(unsigned int format)
{
#ifdef ICECAST
	if (shout_set_format(shout, format) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0017);
	}

	logSrv->info("Shout format set");
#endif
}

void LibShout::setProtocol(unsigned int protocol)
{
#ifdef ICECAST
	if (shout_set_protocol(shout, protocol) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0018);
	}

	logSrv->info("Shout protocol set");
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

void LibShout::setNonblocking(unsigned int nonblocking)
{
#ifdef ICECAST
	if (shout_set_nonblocking(shout, nonblocking) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0019);
	}

	logSrv->info("Shout non-blocking set");
#endif
}

int LibShout::shoutOpen()
{
#ifdef ICECAST
	shout_open(shout);
#endif
}

int LibShout::shoutClose()
{
#ifdef ICECAST
	shout_open(shout);
#endif
}

int LibShout::shoutSend(const unsigned char *data, size_t len)
{
#ifdef ICECAST
	shout_send(shout, data, len);
#endif
}
