#include "LibShout.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../exception/IcecastDomainErrorCode.h"
#include "../../kernel/converter/Convert.h"

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
