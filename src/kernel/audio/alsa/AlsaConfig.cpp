#include "AlsaConfig.h"

AlsaConfig::AlsaConfig(
    string device,
    unsigned int rate,
    int channels,
    string format,
    int bufferFrameSize):
    device(device),
    rate(rate),
    channels(channels),
    format(format),
    bufferFrameSize(bufferFrameSize)
{

}

AlsaConfig::~AlsaConfig()
{

}

string AlsaConfig::getDevice()
{
    return device;
}

unsigned int AlsaConfig::getRate()
{
    return rate;
}

int AlsaConfig::getChannels()
{
    return channels;
}

string AlsaConfig::getStringFormat()
{
    return format;
}

#ifdef ALSA
snd_pcm_format_t AlsaConfig::getFormat()
{
    // TODO: Change it to the propper
    return SND_PCM_FORMAT_S16_LE;
}
#endif

int AlsaConfig::getBufferFrameSize()
{
    return bufferFrameSize;
}
