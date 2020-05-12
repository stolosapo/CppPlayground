#ifndef AlsaAudioSource_h__
#define AlsaAudioSource_h__

#include <iostream>
#include <string>

#ifdef ALSA
#include <alsa/asoundlib.h>
#endif

#include "AlsaConfig.h"

using namespace std;

class AlsaAudioSource
{
private:
    AlsaConfig *config;

#ifdef ALSA
    snd_pcm_t* initialize();
#endif

public:
    AlsaAudioSource(AlsaConfig *config);
    virtual ~AlsaAudioSource();

    void capture();
};

#endif // AlsaAudioSource_h__
