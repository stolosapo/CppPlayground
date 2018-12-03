#include "LameAudioEncodingService.h"

#include "../../../converter/Convert.h"
#include "../../../utils/FileHelper.h"

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

void LameAudioEncodingService::write16BitsLowHigh(FILE* file, int value)
{
    unsigned char bytes[2];
    bytes[0] = (value & 0xff);
    bytes[1] = ((value >> 8) & 0xff);
    fwrite(bytes, 1, 2, file);
}

void LameAudioEncodingService::write32BitsLowHigh(FILE* file, int value)
{
    unsigned char bytes[4];
    bytes[0] = (value & 0xff);
    bytes[1] = ((value >> 8) & 0xff);
    bytes[2] = ((value >> 16) & 0xff);
    bytes[3] = ((value >> 24) & 0xff);
    fwrite(bytes, 1, 4, file);
}

void LameAudioEncodingService::writeWaveHeader(FILE* const file, int pcm_bytes, int frequency, int channels, int bits)
{
    int bytes = (bits + 7) / 8;

    /* quick and dirty, but documented */

    /* label */
    fwrite("RIFF", 1, 4, file);

    /* length in bytes without header */
    write32BitsLowHigh(file, pcm_bytes + 44 - 8);

    /* 2 labels */
    fwrite("WAVEfmt ", 2, 4, file);

    /* length of PCM format declaration area */
    write32BitsLowHigh(file, 2 + 2 + 4 + 4 + 2 + 2);

    /* is PCM? */
    write16BitsLowHigh(file, 1);

    /* number of channels */
    write16BitsLowHigh(file, channels);

    /* sample frequency in [Hz] */
    write32BitsLowHigh(file, frequency);

    /* bytes per second */
    write32BitsLowHigh(file, frequency * channels * bytes);

    /* bytes per sample time */
    write16BitsLowHigh(file, channels * bytes);

    /* bits per sample */
    write16BitsLowHigh(file, bits);

    /* label */
    fwrite("data", 1, 4, file);

    /* length in bytes of raw PCM data */
    write32BitsLowHigh(file, pcm_bytes);
}

void LameAudioEncodingService::encode(const char* filename)
{

}

void LameAudioEncodingService::encode(
    string pcm_in_file,
    string mp3_out_file,
    AudioTag* settings)
{
    LibLame lame;

    initialize(lame, settings);

    int read = 0;
    int write = 0;

    long PCM_total_size = 0;
    long cumulative_read = 0;

    FILE *pcm = FileHelper::openReadBinary(pcm_in_file);
    FILE *mp3 = FileHelper::openWriteBinary(mp3_out_file);

    fseek(pcm, 0, SEEK_END);
    PCM_total_size = ftell(pcm);
    fseek(pcm, 0, SEEK_SET);

    unsigned char* buffer = new unsigned char[LibLame::MAX_MP3_BUFFER];

    short int pcm_buffer[PCM_SIZE * 2];
    unsigned char mp3_buffer[MP3_SIZE];


    /* Progress Log: STARTED */


    int imp3 = lame.getId3v2Tag(buffer, LibLame::MAX_MP3_BUFFER);

    // Write the id3v2 tag
    fwrite(buffer, sizeof(char), imp3, mp3);

    // Store beginning of audio data
    long audio_pos = ftell(mp3);


    do
    {
        read = fread(pcm_buffer, 2 * sizeof(short int), PCM_SIZE, pcm);

        cumulative_read += (long) read * 2 * sizeof(short int);

        if (read == 0)
        {
            write = lame.encodeFlush(mp3_buffer, MP3_SIZE);
        }
        else
        {
            write = lame.encodeBufferInterleaved(pcm_buffer, read, mp3_buffer, MP3_SIZE);
        }

        fwrite(mp3_buffer, write, sizeof(char), mp3);

        /* Progress Log: COMPUTED */
        int percentage = ((float) cumulative_read / PCM_total_size) * 100;

    } while (read != 0);


    imp3 = lame.getId3v1Tag(buffer, LibLame::MAX_MP3_BUFFER);
    fwrite(buffer, sizeof(char), imp3, mp3);

    imp3 = lame.getLameTagFrame(buffer, LibLame::MAX_MP3_BUFFER);
    if (fseek(mp3, audio_pos, SEEK_SET) != 0)
    {
        // log warning: WARNING: can't seek back to update LAME-tag frame!
    }
    fwrite(buffer, sizeof(char), imp3, mp3);
	delete [] buffer;

    fclose(mp3);
	fclose(pcm);

    /* Progress Log: DONE */

    lame.close();
}

void LameAudioEncodingService::decode(string mp3_in_file, string pcm_out_file)
{
    int read;
    int i;
    int samples;

    // use to count the number of mp3 byte read, this is used to write the length of the wave file
    long wav_size = 0;
    long cumulative_read = 0;

    short int pcm_l[PCM_SIZE];
    short int pcm_r[PCM_SIZE];

    unsigned char mp3_buffer[MP3_SIZE];

    FILE* pcm = FileHelper::openWriteBinary(pcm_out_file);
    FILE* mp3 = FileHelper::openReadBinary(mp3_in_file);

    fseek(mp3, 0, SEEK_END);
    long MP3_total_size = ftell(mp3);
    fseek(mp3, 0, SEEK_SET);

    LibLame lame;

    lame.init();
    lame.setDecodeOnly(true);
    lame.initParams();

}
