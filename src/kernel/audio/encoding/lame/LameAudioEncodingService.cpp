#include "LameAudioEncodingService.h"

#include "../../../converter/Convert.h"

/*
Example
https://stackoverflow.com/questions/2495420/is-there-any-lame-c-wraper-simplifier-working-on-linux-mac-and-win-from-pure/2496831#2496831

https://www.codeproject.com/Articles/656543/The-LAME-wrapper-An-audio-converter

https://codereview.stackexchange.com/questions/83504/basic-c-tone-generator

https://stackoverflow.com/questions/9137297/generating-sounds-without-a-library

https://medium.com/@audiowaves/lets-write-a-simple-sine-wave-generator-with-c-and-juce-c8ab42d1f54f

https://github.com/pbohun/sound-gen/blob/master/lesson2/sound.h
*/

LameAudioEncodingService::LameAudioEncodingService() : AudioEncodingService()
{
    cout << "Lame Implementation" << endl;
}

LameAudioEncodingService::~LameAudioEncodingService()
{

}

void LameAudioEncodingService::initialize(LibLame& lame, AudioTag* settings)
{
    lame.init();
    lame.setInSamplerate(settings->getSamplerate());
    lame.setOutSamplerate(settings->getReSamplerate());
    lame.setFindReplayGain(true);

    setId3Tag(lame, settings);
    setChannels(lame, settings);
    setVbrTag(lame, settings);

    lame.initParams();
}

void LameAudioEncodingService::setId3Tag(LibLame& lame, AudioTag* settings)
{
    lame.id3tagInit();
    lame.id3tagV2Only();

    if (settings->getYear() != 0)
    {
        lame.id3tagSetYear(Convert<int>::NumberToString(settings->getYear()));
    }

    lame.id3tagSetGenre(settings->getGenre());
    lame.id3tagSetArtist(settings->getArtist());
    lame.id3tagSetAlbum(settings->getAlbum());
    lame.id3tagSetTitle(settings->getTitle());
    lame.id3tagSetTrack(Convert<int>::NumberToString(settings->getTrack()));
    lame.id3tagSetComment(settings->getComments());
    // lame.id3tagSetAlbumArt(...);

    lame.setWriteId3tagAutomatic(false);
}

void LameAudioEncodingService::setChannels(LibLame& lame, AudioTag* settings)
{
    int channels = settings->getChannels();

    if (channels == 1)
    {
        lame.setModeMono();
        lame.setNumChannels(1);
    }
    else
    {
        lame.setModeJointStereo();
        lame.setNumChannels(2);
    }
}

void LameAudioEncodingService::setVbrTag(LibLame& lame, AudioTag* settings)
{
    lame.setBWriteVbrTag(true);

    switch (settings->getEncodeMode())
    {
        case ABR:
            setEncodeModeABR(lame, settings);
            break;
        case CBR:
            setEncodeModeCBR(lame, settings);
            break;
        case VBR:
            setEncodeModeVBR(lame, settings);
            break;
        default:
            break;
    }
}

void LameAudioEncodingService::setEncodeModeABR(LibLame& lame, AudioTag* settings)
{
    int a_br = settings->getAudioBitrate();

    if(a_br >= 8000)
    {
        a_br = (a_br + 500) / 1000;
    }

    if(a_br > 320)
    {
        a_br = 320;
    }

    if(a_br < 8)
    {
        a_br = 8;
    }

    lame.setVBR_ABR();
    lame.setVBRMeanBitrateKbps(a_br);
}

void LameAudioEncodingService::setEncodeModeCBR(LibLame& lame, AudioTag* settings)
{
    lame.setVBR_OFF();
    lame.setQuality(settings->getQuality());
    lame.setBrate(settings->getAudioBitrate());
}

void LameAudioEncodingService::setEncodeModeVBR(LibLame& lame, AudioTag* settings)
{
    lame.setVBR_MTRH();
    lame.setVBRq(settings->getQuality());
}

void LameAudioEncodingService::encode(const char* filename)
{

}

int LameAudioEncodingService::encode(
    string pcm_in_file,
    string mp3_out_file,
    AudioTag* settings)
{
    LibLame lame;

    initialize(lame, settings);

    int lResult = 0;

    return lResult;
}
