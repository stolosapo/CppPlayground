#ifndef LameAudioEncodingService_h__
#define LameAudioEncodingService_h__

#include <iostream>
#include <string>

#ifdef LAME
#include <lame/lame.h>
#endif

#include "../AudioEncodingService.h"

using namespace std;

class LameAudioEncodingService: public AudioEncodingService
{
private:

    int mp3_readpcm(
        const int audio_buffer_size,
        int read_size,
        unsigned char* audio_original_buffer,
        short int* left,
        short int* right);

    int decode(
        unsigned char* buffer,
        size_t bufflen,
        short int* left,
        short int* right);

#ifdef LAME
    int reencode(
        lame_t lame,
        int samples,
        short int* left,
        short int* right,
        unsigned char* audio_encoded_buffer,
        int audio_encoded_buffer_len);

    int flush(lame_t lame, unsigned char* audio_encoded_buffer, int max_len);
#endif

public:
	LameAudioEncodingService();
	virtual ~LameAudioEncodingService();

	virtual void encode(const char* filename);

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
