#ifndef Version_h__
#define Version_h__

#include <iostream>
#include <string>

using namespace std;

class Version
{
private:
	const int MAJOR_VERSION;
	const int MINOR_VERSION;
	const int PATCH_VERSION;

public:
	Version(const int major, const int minor, const int patch);
	virtual ~Version();

	const int majorVersion() const;
	const int minorVersion() const;
	const int patchVersion() const;

	string version() const;
};

#endif // Version_h__
