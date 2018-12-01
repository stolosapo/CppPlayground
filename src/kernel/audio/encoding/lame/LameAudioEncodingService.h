#ifndef LameAudioEncodingService_h__
#define LameAudioEncodingService_h__

#include <iostream>
#include <string>

#include "../AudioEncodingService.h"
#include "../../AudioTag.h"
#include "../liblame/LibLame.h"

using namespace std;

class LameAudioEncodingService: public AudioEncodingService
{
private:
    void initialize(LibLame& lame, AudioTag* settings);
    void setId3Tag(LibLame& lame, AudioTag* settings);
    void setChannels(LibLame& lame, AudioTag* settings);
    void setVbrTag(LibLame& lame, AudioTag* settings);
    void setEncodeModeABR(LibLame& lame, AudioTag* settings);
    void setEncodeModeCBR(LibLame& lame, AudioTag* settings);
    void setEncodeModeVBR(LibLame& lame, AudioTag* settings);

public:
	LameAudioEncodingService();
	virtual ~LameAudioEncodingService();

	virtual void encode(const char* filename);

    virtual int encode(
        string pcm_in_file,
        string mp3_out_file,
        AudioTag* settings);
};

#endif // LameAudioEncodingService_h__
