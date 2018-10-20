#include "LameAudioEncodingService.h"

#ifdef LAME
#include <lame/lame.h>
#endif

/*
Example
https://stackoverflow.com/questions/2495420/is-there-any-lame-c-wraper-simplifier-working-on-linux-mac-and-win-from-pure/2496831#2496831
*/

LameAudioEncodingService::LameAudioEncodingService() : AudioEncodingService()
{
    cout << "Lame Implementation" << endl;
}

LameAudioEncodingService::~LameAudioEncodingService()
{

}

void LameAudioEncodingService::encode(const char* filename)
{

}

int LameAudioEncodingService::decode(
    unsigned char* buffer,
    size_t bufflen,
    short int* left,
    short int* right)
{
    int res = 0;

#ifdef LAME
    // res = lame_decode(buffer, bufflen, left, right);
#endif

    return res;
}

int LameAudioEncodingService::test_encode(
    int samplerate,
    int bitrate,
    int channels,
    const int audio_size,
    int original_read,
    short int* pcm_original_buffer,
    unsigned char* audio_encoded_buffer)
{
    int write;

#ifdef LAME

    lame_t lame = lame_init();
    lame_set_in_samplerate(lame, samplerate);
    lame_set_num_channels(lame, channels);
    lame_set_brate(lame, bitrate);
    lame_set_quality(lame, 5); /* 2=high  5=medium  7=low */
    lame_set_VBR(lame, vbr_default);
    lame_init_params(lame);

    if (original_read == 0)
    {
        write = lame_encode_flush(lame, audio_encoded_buffer, audio_size);
    }
    else
    {
        write = lame_encode_buffer_interleaved(lame, pcm_original_buffer, original_read, audio_encoded_buffer, audio_size);
    }

    lame_close(lame);

#endif

    return write;
}
