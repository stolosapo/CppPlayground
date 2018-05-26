#include "TagLibAudioTagService.h"

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>

#include "../../converter/Convert.h"

#ifdef TAGLIB
#include <taglib/fileref.h>
#include <taglib/tag.h>
#include <taglib/tpropertymap.h>
#endif

using namespace std;

TagLibAudioTagService::TagLibAudioTagService() : AudioTagService()
{

}

TagLibAudioTagService::~TagLibAudioTagService()
{

}

AudioTag* TagLibAudioTagService::read(const char* filename)
{
	string title = "";
	string artist = "";
	string album = "";
	string comment = "";
	string genre = "";
	int year = 0;
	int track = 0;

	int duration = 0;
	string strDuration = "--:--";
	int bitrate = 0;
	int samplerate = 0;
	int channels = 0;

#ifdef TAGLIB
	TagLib::FileRef f(filename);

	if (!f.isNull() && f.tag())
	{
		TagLib::Tag *tag = f.tag();

		bool unicode = true;

		title = tag->title().toCString(unicode);
		artist = tag->artist().toCString(unicode);
		album = tag->album().toCString(unicode);
		comment = tag->comment().toCString(unicode);
		genre = tag->genre().toCString(unicode);
		year = tag->year();
		track = tag->track();

		// delete tag;
	}

	if (!f.isNull() && f.audioProperties())
	{
		TagLib::AudioProperties *properties = f.audioProperties();

		int seconds = properties->length() % 60;
		int minutes = (properties->length() - seconds) / 60;

		string s = Convert<int>::NumberToString(seconds);
		string m = Convert<int>::NumberToString(minutes);

		duration = properties->length();
		strDuration = s + ":" + m;
		bitrate = properties->bitrate();
		samplerate = properties->sampleRate();
		channels = properties->channels();

		// delete properties;
	}
#endif

	return new AudioTag(title,
		 artist,
		 album,
		 comment,
		 genre,
		 year,
		 track,
		 duration,
		 strDuration,
		 bitrate,
		 samplerate,
		 channels);
}
