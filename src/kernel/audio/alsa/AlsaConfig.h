#ifndef AlsaConfig_h__
#define AlsaConfig_h__

#include <iostream>
#include <string>

#ifdef ALSA
#include <alsa/asoundlib.h>
#endif

using namespace std;

class AlsaConfig
{
private:
    string device;

    unsigned int rate;
    int channels;
    string format;
    int bufferFrameSize;

public:
    AlsaConfig(
        string device,
        unsigned int rate,
        int channels,
        string format,
        int bufferFrameSize);
    virtual ~AlsaConfig();

    string getDevice();

    unsigned int getRate();
    int getChannels();
    string getStringFormat();

#ifdef ALSA
    snd_pcm_format_t getFormat();
#endif

    int getBufferFrameSize();
};

#endif // AlsaConfig_h__
