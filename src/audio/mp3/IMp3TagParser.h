#ifndef IMp3TagParser_h__
#define IMp3TagParser_h__

#include <fstream>

#include "../AudioMetadata.h"

using namespace std;

class IMp3TagParser
{
private:
	AudioType type;
	AudioTagVersion tagVersion;

protected:
	virtual AudioType getType();
	virtual AudioTagVersion getTagVersion();

public:
	IMp3TagParser(AudioType type, AudioTagVersion tagVersion);
	virtual ~IMp3TagParser();

	virtual AudioMetadata* parse(FILE* file) = 0;
	virtual bool isCorrectVersion(FILE* file) = 0;

};

#endif // IMp3TagParser_h__
