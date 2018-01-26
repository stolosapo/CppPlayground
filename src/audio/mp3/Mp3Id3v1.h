#ifndef Mp3Id3v1_h__
#define Mp3Id3v1_h__

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Mp3Id3v1
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
        void readMP3(FILE *file);

public:
	Mp3Id3v1();
	virtual ~Mp3Id3v1();

	virtual void load(const char* filename);

        virtual bool isCorrectVersion();

        virtual string getTitle();
        virtual string getArtist();
        virtual string getAlbum();
        virtual string getYear();
        virtual string getComments();
};

#endif // Mp3Id3v1_h__