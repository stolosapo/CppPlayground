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

	metadata = shout_metadata_new();
#endif
}

void LibShout::shoutFree()
{
#ifdef ICECAST
	shout_free(shout);
	shout_metadata_free(metadata);
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
		throw DomainException(IcecastDomainErrorCode::ICS0003, getError());
	}
#endif
}

string LibShout::getHost()
{
#ifdef ICECAST
	return string(shout_get_host(shout));
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
#endif
}

void LibShout::setAgent(string agent)
{
#ifdef ICECAST
	if (shout_set_agent(shout, agent.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0005, getError());
	}
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
#endif
}


void LibShout::setName(string name)
{
#ifdef ICECAST
	if (shout_set_name(shout, name.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0009, getError());
	}
#endif
}

void LibShout::setUrl(string url)
{
#ifdef ICECAST
	if (shout_set_url(shout, url.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0010, getError());
	}
#endif
}

void LibShout::setGenre(string genre)
{
#ifdef ICECAST
	if (shout_set_genre(shout, genre.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0011, getError());
	}
#endif
}

void LibShout::setDescription(string description)
{
#ifdef ICECAST
	if (shout_set_description(shout, description.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0012, getError());
	}
#endif
}

void LibShout::setDumpfile(string dumpfile)
{
#ifdef ICECAST
	if (shout_set_dumpfile(shout, dumpfile.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0013, getError());
	}
#endif
}

void LibShout::setAudioInfo(string name, string value)
{
#ifdef ICECAST
	if (shout_set_audio_info(shout, name.c_str(), value.c_str()) != SHOUTERR_SUCCESS)
	{
		string mess = name + ":" + value;
		throw DomainException(IcecastDomainErrorCode::ICS0014, getError());
	}
#endif
}

void LibShout::setAudioInfoBitrate(string value)
{
#ifdef ICECAST
	setAudioInfo(SHOUT_AI_BITRATE, value);
#endif
}

void LibShout::setAudioInfoSamplerate(string value)
{
#ifdef ICECAST
	setAudioInfo(SHOUT_AI_SAMPLERATE, value);
#endif
}

void LibShout::setAudioInfoChannels(string value)
{
#ifdef ICECAST
	setAudioInfo(SHOUT_AI_CHANNELS, value);
#endif
}

void LibShout::setAudioInfoQuality(string value)
{
#ifdef ICECAST
	setAudioInfo(SHOUT_AI_QUALITY, value);
#endif
}


#ifdef ICECAST
shout_metadata_t*  LibShout::createNewMetadata()
{
	shout_metadata_t* newMetadata;

	if (!(newMetadata = shout_metadata_new()))
	{
		throw DomainException(IcecastDomainErrorCode::ICS0015, getError());
	}

	return newMetadata;
}

void LibShout::setMeta(shout_metadata_t* newMetadata)
{
	int m = shout_set_metadata(shout, newMetadata);

	if (m != SHOUTERR_SUCCESS)
	{
		logSrv->warn("Updating metadata failed. " + getError());
	}
}

void LibShout::setMeta(shout_metadata_t* metadata, string name, string value)
{
	if (shout_metadata_add(metadata, name.c_str(), value.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0015, getError());
	}
}

void LibShout::setMetaSong(shout_metadata_t* metadata, string song)
{
	setMeta(metadata, "song", song);
}

void LibShout::freeMetadate(shout_metadata_t* metadata)
{
	shout_metadata_free(metadata);
}
#endif


void LibShout::setMeta()
{
#ifdef ICECAST
	int m = shout_set_metadata(shout, metadata);

	if (m != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0015);
	}
#endif
}

void LibShout::setMeta(string name, string value)
{
#ifdef ICECAST
	if (shout_metadata_add(metadata, name.c_str(), value.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0015, getError());
	}
#endif
}

void LibShout::setMetaName(string value)
{
#ifdef ICECAST
	setMeta(SHOUT_META_NAME, value);
#endif
}

void LibShout::setMetaUrl(string value)
{
#ifdef ICECAST
	setMeta(SHOUT_META_URL, value);
#endif
}

void LibShout::setMetaGenre(string value)
{
#ifdef ICECAST
	setMeta(SHOUT_META_GENRE, value);
#endif
}

void LibShout::setMetaDescription(string value)
{
#ifdef ICECAST
	setMeta(SHOUT_META_DESCRIPTION, value);
#endif
}

void LibShout::setMetaIrc(string value)
{
#ifdef ICECAST
	setMeta(SHOUT_META_IRC, value);
#endif
}

void LibShout::setMetaAim(string value)
{
#ifdef ICECAST
	setMeta(SHOUT_META_AIM, value);
#endif
}

void LibShout::setMetaIcq(string value)
{
#ifdef ICECAST
	setMeta(SHOUT_META_ICQ, value);
#endif
}

void LibShout::setPublic(unsigned int make_public)
{
#ifdef ICECAST
	if (shout_set_public(shout, make_public) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0016, getError());
	}
#endif
}

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

void LibShout::setProtocol(unsigned int protocol)
{
#ifdef ICECAST
	if (shout_set_protocol(shout, protocol) != SHOUTERR_SUCCESS)
	{
		throw DomainException(IcecastDomainErrorCode::ICS0018, getError());
	}
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
		throw DomainException(IcecastDomainErrorCode::ICS0019, getError());
	}
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
