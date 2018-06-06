#ifndef AudioMetadata_h__
#define AudioMetadata_h__

#include <string>

#include "AudioType.h"
#include "AudioTagVersion.h"

using namespace std;

class AudioMetadata
{
private:
	AudioType type;
	AudioTagVersion tagVersion;

	string title;
	string artist;
	string album;
	string year;
	string comments;

public:
	AudioMetadata(
		AudioType type, 
		AudioTagVersion tagVersion, 
		string title, 
		string artist, 
		string album, 
		string year, 
		string comments);

	virtual ~AudioMetadata();

	virtual AudioType getType();
	virtual AudioTagVersion getTagVersion();

	virtual string getTitle();
	virtual string getArtist();
	virtual string getAlbum();
	virtual string getYear();
	virtual string getComments();
};

#endif // AudioMetadata_h__
