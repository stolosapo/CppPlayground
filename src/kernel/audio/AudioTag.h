#ifndef AudioTag_h__
#define AudioTag_h__

#include <string>

using namespace std;

class AudioTag
{
private:
	string title;
	string artist;
	string album;
	string comments;
	string genre;
	int year;
	int track;

	int duration;
	int bitrate;
	int samplerate;
	int channels;

public:
	AudioTag(string title,
		string artist,
		string album,
		string comments,
		string genre,
		int year,
		int track,
		int duration,
		int bitrate,
		int samplerate,
		int channels);

	virtual ~AudioTag();

	virtual string getTitle();
	virtual string getArtist();
	virtual string getAlbum();
	virtual string getComments();
	virtual string getGenre();
	virtual int getYear();
	virtual int getTrack();

	virtual int getDuration();
	virtual int getBitrate();
	virtual int getSamplerate();
	virtual int getChannels();
};

#endif // AudioTag_h__
