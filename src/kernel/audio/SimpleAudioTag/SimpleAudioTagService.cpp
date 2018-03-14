#include "SimpleAudioTagService.h"

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>

using namespace std;

SimpleAudioTagService::SimpleAudioTagService() : AudioTagService()
{

}

SimpleAudioTagService::~SimpleAudioTagService()
{
        /* Clear parsers*/
        for (vector<AudioTagParser*>::iterator it = tagParsers.begin();
                it != tagParsers.end();
                ++it)
        {
                delete *it;
        }

        tagParsers.clear();
}

void SimpleAudioTagService::registerParsers()
{
	// tagParsers.push_back(new Mp3Id3v1);
}

AudioTag* SimpleAudioTagService::read(const char* filename)
{
        string title = "";
        string artist = "";
        string album = "";
        string comment = "";
        string genre = "";
        int year = 0;
        int track = 0;

        int duration = 0;
        int bitrate = 0;
        int samplerate = 0;
        int channels = 0;

        return new AudioTag(title,
                 artist,
                 album,
                 comment,
                 genre,
                 year,
                 track,
                 duration,
                 bitrate,
                 samplerate,
                 channels);
}
