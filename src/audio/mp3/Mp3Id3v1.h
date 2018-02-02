#ifndef Mp3Id3v1_h__
#define Mp3Id3v1_h__

#include <iostream>
#include <string>
#include <fstream>

#include "Mp3TagParser.h"

using namespace std;

class Mp3Id3v1 : public Mp3TagParser
{
private:
	string title;
	string artist;
	string album;
	string year;
	string comments;

	bool correctVersion;

	int getSize(FILE *file);
	bool checkMp3(string filename);
	string readHeader(FILE *file, int readloc);
	string readYear(FILE *file, int readloc);
	string readThirty(FILE *file, int readloc);
	AudioMetadata* readMP3(FILE *file);

public:
	Mp3Id3v1();
	virtual ~Mp3Id3v1();

	virtual void load(const char* filename);

	virtual AudioMetadata* parse(FILE* file);
	virtual bool isCorrectVersion(FILE* file);
	
	virtual bool isCorrectVersion();

	virtual string getTitle();
	virtual string getArtist();
	virtual string getAlbum();
	virtual string getYear();
	virtual string getComments();
};

#endif // Mp3Id3v1_h__
