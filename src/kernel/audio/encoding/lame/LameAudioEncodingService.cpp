#include "LameAudioEncodingService.h"

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

int LameAudioEncodingService::mp3_readpcm(
    const int audio_buffer_size,
    int read_size,
    unsigned char* audio_original_buffer,
    short int* left,
    short int* right)
{
    unsigned char buf[audio_buffer_size];
    int samples = 0;

    if (read_size <= 0)
    {
        return read_size;
    }

    while (!samples)
    {
        samples = decode(audio_original_buffer, read_size, left, right);
    }

    return samples;
}

int LameAudioEncodingService::decode(
    unsigned char* buffer,
    size_t bufflen,
    short int* left,
    short int* right)
{
    int res = 0;

#ifdef LAME
    // res = hip_decode(buffer, bufflen, left, right);
#endif

    return res;
}

#ifdef LAME
int LameAudioEncodingService::reencode(
    lame_t lame,
    int samples,
    short int* left,
    short int* right,
    unsigned char* audio_encoded_buffer,
    int audio_encoded_buffer_len)
{
    return lame_encode_buffer(lame, left, right, samples, audio_encoded_buffer, audio_encoded_buffer_len);
}

int LameAudioEncodingService::flush(lame_t lame, unsigned char* audio_encoded_buffer, int max_len)
{
    return lame_encode_flush_nogap(lame, audio_encoded_buffer, max_len);
}
#endif

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
