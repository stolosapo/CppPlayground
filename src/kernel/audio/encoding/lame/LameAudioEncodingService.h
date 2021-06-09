#ifndef LameAudioEncodingService_h__
#define LameAudioEncodingService_h__

#include <iostream>
#include <string>

#include "../AudioEncodingService.h"
#include "../liblame/LibLame.h"

using namespace std;

class LameAudioEncodingService: public AudioEncodingService
{
private:
    static const int PCM_SIZE = 4096;
	static const int MP3_SIZE = 4096;

    void initialize(LibLame& lame, AudioTag* settings);
    void setId3Tag(LibLame& lame, AudioTag* settings);
    void setChannels(LibLame& lame, AudioTag* settings);
    void setVbrTag(LibLame& lame, AudioTag* settings);
    void setEncodeModeABR(LibLame& lame, AudioTag* settings);
    void setEncodeModeCBR(LibLame& lame, AudioTag* settings);
    void setEncodeModeVBR(LibLame& lame, AudioTag* settings);

    void write16BitsLowHigh(FILE* file, int value);
    void write32BitsLowHigh(FILE* file, int value);
    void writeWaveHeader(FILE* const file, int pcm_bytes, int frequency, int channels, int bits);

public:
	LameAudioEncodingService();
	virtual ~LameAudioEncodingService();

    virtual string version();

    virtual void encode(string pcm_in_file, string mp3_out_file, AudioTag* settings);
    virtual void decode(string mp3_in_file, string pcm_out_file);

    virtual int reencode(unsigned char* mp3_in_buffer, int mp3_in_buffer_size, unsigned char* mp3_out_buffer, AudioTag* settings);
};

#endif // LameAudioEncodingService_h__
