#ifndef Mp3MetadataParser_h__
#define Mp3MetadataParser_h__

#include <vector>

#include "Mp3TagParser.h"
#include "../AudioMetadata.h"

using namespace std;

class Mp3MetadataParser
{
private:
	vector<Mp3TagParser*> tagParsers;

	void registerParsers();
	bool checkMp3(string filename);

public:
	Mp3MetadataParser();
	virtual ~Mp3MetadataParser();

	virtual AudioMetadata* parse(const char* filename);

};

#endif // Mp3MetadataParser_h__
