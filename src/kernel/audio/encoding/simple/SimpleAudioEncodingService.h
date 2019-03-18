#ifndef SimpleAudioEncodingService_h__
#define SimpleAudioEncodingService_h__

#include <iostream>
#include <string>

#include "../AudioEncodingService.h"

using namespace std;

class SimpleAudioEncodingService: public AudioEncodingService
{
public:
	SimpleAudioEncodingService();
	virtual ~SimpleAudioEncodingService();

    virtual string version();

    virtual void encode(string pcm_in_file, string mp3_out_file, AudioTag* settings);
    virtual void decode(string mp3_in_file, string pcm_out_file);
};

#endif // SimpleAudioEncodingService_h__
