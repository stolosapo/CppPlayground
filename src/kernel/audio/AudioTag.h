#ifndef AudioTag_h__
#define AudioTag_h__

#include <string>

#include "encoding/AudioEncodeMode.h"
#include "AudioBitrate.h"

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
	string strDuration;
	int bitrate;
	int samplerate;
	int channels;

    AudioEncodeMode encodeMode;
    AudioBitrate audioBitrate;
    int reSamplerate;
    int quality;

public:
	AudioTag(string title,
		string artist,
		string album,
		string comments,
		string genre,
		int year,
		int track,
		int duration,
		string strDuration,
		int bitrate,
		int samplerate,
		int channels);

	virtual ~AudioTag();

    static AudioTag* empty();
    static AudioTag* emptyWithTitle(string title);

	virtual string getTitle();
	virtual string getArtist();
	virtual string getAlbum();
	virtual string getComments();
	virtual string getGenre();
	virtual int getYear();
	virtual int getTrack();

	virtual int getDuration();
	virtual string getStrDuration();
	virtual int getBitrate();
	virtual int getSamplerate();
	virtual int getChannels();

    virtual AudioEncodeMode getEncodeMode();
    virtual AudioBitrate getAudioBitrate();
    virtual int getReSamplerate();
    virtual int getQuality();

    virtual void setReencodeData(AudioEncodeMode encodeMode, AudioBitrate audioBitrate, int reSamplerate, int quality);
};

#endif // AudioTag_h__
