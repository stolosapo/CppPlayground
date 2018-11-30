#include "AudioTag.h"

AudioTag::AudioTag(string title,
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
        int channels) :
        title(title),
        artist(artist),
        album(album),
        comments(comments),
        genre(genre),
        year(year),
        track(track),
        duration(duration),
        strDuration(strDuration),
        bitrate(bitrate),
        samplerate(samplerate),
        channels(channels)
{

}

AudioTag::~AudioTag()
{

}

AudioTag* AudioTag::empty()
{
    return new AudioTag(
        "",
		"",
		"",
		"",
		"",
		0,
		0,
		0,
		"--:--",
		0,
		0,
		0);
}

AudioTag* AudioTag::emptyWithTitle(string title)
{
    AudioTag* tag = AudioTag::empty();

    tag->title = title;

    return tag;
}

string AudioTag::getTitle()
{
        return title;
}

string AudioTag::getArtist()
{
        return artist;
}

string AudioTag::getAlbum()
{
        return album;
}

string AudioTag::getComments()
{
        return comments;
}

string AudioTag::getGenre()
{
        return genre;
}

int AudioTag::getYear()
{
        return year;
}

int AudioTag::getTrack()
{
        return track;
}

int AudioTag::getDuration()
{
        return duration;
}

string AudioTag::getStrDuration()
{
        return strDuration;
}

int AudioTag::getBitrate()
{
        return bitrate;
}

int AudioTag::getSamplerate()
{
        return samplerate;
}

int AudioTag::getChannels()
{
        return channels;
}
