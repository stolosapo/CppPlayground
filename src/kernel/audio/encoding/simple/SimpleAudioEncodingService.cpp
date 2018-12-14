#include "SimpleAudioEncodingService.h"

SimpleAudioEncodingService::SimpleAudioEncodingService() : AudioEncodingService()
{
    cout << "Simple Implementation" << endl;
}

SimpleAudioEncodingService::~SimpleAudioEncodingService()
{

}

string SimpleAudioEncodingService::version()
{
    return "";
}

void SimpleAudioEncodingService::encode(string pcm_in_file, string mp3_out_file, AudioTag* settings)
{

}

void SimpleAudioEncodingService::decode(string mp3_in_file, string pcm_out_file)
{

}
