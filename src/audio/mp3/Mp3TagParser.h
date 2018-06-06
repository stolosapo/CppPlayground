#ifndef Mp3TagParser_h__
#define Mp3TagParser_h__

#include <fstream>

#include "../AudioMetadata.h"

using namespace std;

class Mp3TagParser
{
private:
	AudioType type;
	AudioTagVersion tagVersion;

protected:
	virtual AudioType getType();
	virtual AudioTagVersion getTagVersion();

public:
	Mp3TagParser(AudioType type, AudioTagVersion tagVersion);
	virtual ~Mp3TagParser();

	virtual AudioMetadata* parse(FILE* file) = 0;
	virtual bool isCorrectVersion(FILE* file) = 0;

};

#endif // Mp3TagParser_h__
