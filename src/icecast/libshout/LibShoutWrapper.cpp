#include "LibShout.h"

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
		logSrv->error("Could not allocate shout_t");
		return;
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

int LibShout::setHost(string host)
{
#ifdef ICECAST
	int result = shout_set_host(shout, host.c_str());

	if (result != SHOUTERR_SUCCESS) 
	{
		logSrv->error("Error setting hostname: " + getError());
		return result;
	}
	
	logSrv->info("Shout hostname set");
	return result;
#else
	return -1;
#endif
}

int LibShout::setPort(unsigned short port)
{
#ifdef ICECAST
#endif
}

int LibShout::setAgent(string agent)
{
#ifdef ICECAST
#endif
}

int LibShout::setUser(string username)
{
#ifdef ICECAST
#endif
}

int LibShout::setPassword(string password)
{
#ifdef ICECAST
#endif
}

int LibShout::setMount(string mount)
{
#ifdef ICECAST
#endif
}

int LibShout::setName(string name)
{
#ifdef ICECAST
#endif
}

int LibShout::setUrl(string url)
{
#ifdef ICECAST
#endif
}

int LibShout::setGenre(string genre)
{
#ifdef ICECAST
#endif
}

int LibShout::setDescription(string description)
{
#ifdef ICECAST
#endif
}

int LibShout::setDumpfile(string dumpfile)
{
#ifdef ICECAST
#endif
}

int LibShout::setAudioInfo(string name, string value)
{
#ifdef ICECAST
#endif
}

int LibShout::setMeta(string name, string value)
{
#ifdef ICECAST
#endif
}

int LibShout::setPublic(unsigned int make_public)
{
#ifdef ICECAST
#endif
}

int LibShout::setFormat(unsigned int format)
{
#ifdef ICECAST
#endif
}

int LibShout::setProtocol(unsigned int protocol)
{
#ifdef ICECAST
#endif
}

int LibShout::setNonblocking(unsigned int nonblocking)
{
#ifdef ICECAST
#endif
}

int LibShout::shoutOpen()
{
#ifdef ICECAST
#endif
}

int LibShout::shoutClose()
{
#ifdef ICECAST
#endif
}

int LibShout::shoutSend(const unsigned char *data, size_t len)
{
#ifdef ICECAST
#endif
}