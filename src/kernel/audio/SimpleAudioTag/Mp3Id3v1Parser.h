#ifndef Mp3Id3v1Parser_h__
#define Mp3Id3v1Parser_h__

#include <iostream>
#include <string>
#include <fstream>

#include "AudioTagParser.h"
#include "../AudioTag.h"

using namespace std;

class Mp3Id3v1Parser : public AudioTagParser
{
private:
	int getSize(FILE *file);
	bool checkMp3(string filename);
	string readHeader(FILE *file);
	string readYear(FILE *file, int readloc);
	string readThirty(FILE *file, int readloc);

public:
	Mp3Id3v1Parser();
	virtual ~Mp3Id3v1Parser();

	virtual AudioTag* parse(FILE* file);
	virtual bool isCorrectVersion(FILE* file);
};

#endif // Mp3Id3v1Parser_h__
