#include "Version.h"

#include "../converter/Convert.h"

Version::Version(const int major, const int minor, const int patch)
	: MAJOR_VERSION(major), MINOR_VERSION(minor), PATCH_VERSION(patch)
{

}

Version::~Version()
{

}

const int Version::majorVersion() const
{
	return MAJOR_VERSION;
}

const int Version::minorVersion() const
{
	return MINOR_VERSION;
}

const int Version::patchVersion() const
{
	return PATCH_VERSION;
}

string Version::version() const
{
	string maj = Convert<const int>::NumberToString(MAJOR_VERSION);
	string min = Convert<const int>::NumberToString(MINOR_VERSION);
	string pat = Convert<const int>::NumberToString(PATCH_VERSION);

	string fullVersion = maj + "." + min + "." + pat;

	return fullVersion;
}
