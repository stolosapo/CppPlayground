#ifndef LameAudioEncodingService_h__
#define LameAudioEncodingService_h__

#include <iostream>
#include <string>

#include "../AudioEncodingService.h"

using namespace std;

class LameAudioEncodingService: public AudioEncodingService
{
public:
	LameAudioEncodingService();
	virtual ~LameAudioEncodingService();

	virtual void encode(const char* filename);

    virtual int decode(
        unsigned char* buffer,
        size_t bufflen,
        short int* left,
        short int* right);

    virtual int test_encode(
        int samplerate,
        int bitrate,
        int channels,
        const int audio_size,
        int original_read,
        short int* audio_original_buffer,
        unsigned char* audio_encoded_buffer);
};

#endif // LameAudioEncodingService_h__
