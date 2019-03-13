#include "LibShout.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../exception/NoiseStreamerDomainErrorCode.h"
#include "../../kernel/converter/Convert.h"

void LibShout::setAgent(string agent)
{
#ifdef ICECAST
	if (shout_set_agent(shout, agent.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(NoiseStreamerDomainErrorCode::NSS0005, getError());
	}
#endif
}

void LibShout::setName(string name)
{
#ifdef ICECAST
	if (shout_set_name(shout, name.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(NoiseStreamerDomainErrorCode::NSS0009, getError());
	}
#endif
}

void LibShout::setUrl(string url)
{
#ifdef ICECAST
	if (shout_set_url(shout, url.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(NoiseStreamerDomainErrorCode::NSS0010, getError());
	}
#endif
}

void LibShout::setGenre(string genre)
{
#ifdef ICECAST
	if (shout_set_genre(shout, genre.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(NoiseStreamerDomainErrorCode::NSS0011, getError());
	}
#endif
}

void LibShout::setDescription(string description)
{
#ifdef ICECAST
	if (shout_set_description(shout, description.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(NoiseStreamerDomainErrorCode::NSS0012, getError());
	}
#endif
}

void LibShout::setDumpfile(string dumpfile)
{
#ifdef ICECAST
	if (shout_set_dumpfile(shout, dumpfile.c_str()) != SHOUTERR_SUCCESS)
	{
		throw DomainException(NoiseStreamerDomainErrorCode::NSS0013, getError());
	}
#endif
}

void LibShout::setPublic(unsigned int make_public)
{
#ifdef ICECAST
	if (shout_set_public(shout, make_public) != SHOUTERR_SUCCESS)
	{
		throw DomainException(NoiseStreamerDomainErrorCode::NSS0016, getError());
	}
#endif
}

void LibShout::setNonblocking(unsigned int nonblocking)
{
#ifdef ICECAST
	if (shout_set_nonblocking(shout, nonblocking) != SHOUTERR_SUCCESS)
	{
		throw DomainException(NoiseStreamerDomainErrorCode::NSS0019, getError());
	}
#endif
}
