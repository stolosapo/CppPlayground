#include "AlsaAudioSource.h"

#include <stdio.h>
#include <stdlib.h>
#include <fstream>

#ifdef ALSA
#include <alsa/asoundlib.h>
#endif

#include "../../exception/domain/DomainException.h"
#include "exception/AlsaDomainErrorCode.h"

/*
    https://gist.github.com/ghedo/963382
    http://equalarea.com/paul/alsa-audio.html
    https://gist.github.com/albanpeignier/104902
    https://linuxconfig.org/how-to-test-microphone-with-audio-linux-sound-architecture-alsa
*/

AlsaAudioSource::AlsaAudioSource(AlsaConfig *config): config(config)
{

}

AlsaAudioSource::~AlsaAudioSource()
{

}

#ifdef ALSA
snd_pcm_t* AlsaAudioSource::initialize()
{
    int err;
    unsigned int rate = config->getRate();

    snd_pcm_t *capture_handle;
    snd_pcm_hw_params_t *hw_params;

    if ((err = snd_pcm_open (&capture_handle, config->getDevice().c_str(), SND_PCM_STREAM_CAPTURE, 0)) < 0)
    {
        throw DomainException(AlsaDomainErrorCode::ALS0002, snd_strerror(err));
    }

    if ((err = snd_pcm_hw_params_malloc (&hw_params)) < 0)
    {
        throw DomainException(AlsaDomainErrorCode::ALS0003, snd_strerror(err));
    }

    if ((err = snd_pcm_hw_params_any (capture_handle, hw_params)) < 0)
    {
        throw DomainException(AlsaDomainErrorCode::ALS0004, snd_strerror(err));
    }

    if ((err = snd_pcm_hw_params_set_access (capture_handle, hw_params, SND_PCM_ACCESS_RW_INTERLEAVED)) < 0)
    {
        throw DomainException(AlsaDomainErrorCode::ALS0005, snd_strerror(err));
    }

    if ((err = snd_pcm_hw_params_set_format (capture_handle, hw_params, config->getFormat())) < 0)
    {
        throw DomainException(AlsaDomainErrorCode::ALS0006, snd_strerror(err));
    }

    if ((err = snd_pcm_hw_params_set_rate_near (capture_handle, hw_params, &rate, 0)) < 0)
    {
        throw DomainException(AlsaDomainErrorCode::ALS0007, snd_strerror(err));
    }

    if ((err = snd_pcm_hw_params_set_channels (capture_handle, hw_params, config->getChannels())) < 0)
    {
        throw DomainException(AlsaDomainErrorCode::ALS0008, snd_strerror(err));
    }

    if ((err = snd_pcm_hw_params (capture_handle, hw_params)) < 0)
    {
        throw DomainException(AlsaDomainErrorCode::ALS0009, snd_strerror(err));
    }

    snd_pcm_hw_params_free (hw_params);

    if ((err = snd_pcm_prepare (capture_handle)) < 0)
    {
        throw DomainException(AlsaDomainErrorCode::ALS0015, snd_strerror(err));
    }

    return capture_handle;
}
#endif

void AlsaAudioSource::capture()
{
#ifdef ALSA
    int i;
    int err;
    char *buffer;
    // short buf[128];

    int buffer_frames = config->getBufferFrameSize();
    int channels = config->getChannels();
    // unsigned int rate = 44100;
    // int duration = 1000;

    // const char* dev = "hw:0,0";

    snd_pcm_t *capture_handle = initialize();
    // snd_pcm_hw_params_t *hw_params;
    snd_pcm_format_t format = config->getFormat();

    // if ((err = snd_pcm_open (&capture_handle, dev, SND_PCM_STREAM_CAPTURE, 0)) < 0)
    // {
    //     fprintf (stderr, "cannot open audio device %s (%s)\n",
    //          dev,
    //          snd_strerror (err));
    //     // return;

    //     throw DomainException(AlsaDomainErrorCode::ALS0002, snd_strerror(err));
    // }

    // fprintf(stdout, "audio interface opened\n");

    // if ((err = snd_pcm_hw_params_malloc (&hw_params)) < 0)
    // {
    //     // fprintf (stderr, "cannot allocate hardware parameter structure (%s)\n",
    //     //      snd_strerror (err));
    //     //
    //     // return;

    //     throw DomainException(AlsaDomainErrorCode::ALS0003, snd_strerror(err));
    // }

    // fprintf(stdout, "hw_params allocated\n");

    // if ((err = snd_pcm_hw_params_any (capture_handle, hw_params)) < 0)
    // {
    //     // fprintf (stderr, "cannot initialize hardware parameter structure (%s)\n",
    //     //      snd_strerror (err));
    //     //
    //     // return;

    //     throw DomainException(AlsaDomainErrorCode::ALS0004, snd_strerror(err));
    // }

    // fprintf(stdout, "hw_params initialized\n");

    // if ((err = snd_pcm_hw_params_set_access (capture_handle, hw_params, SND_PCM_ACCESS_RW_INTERLEAVED)) < 0)
    // {
    //     // fprintf (stderr, "cannot set access type (%s)\n",
    //     //      snd_strerror (err));
    //     //
    //     // return;

    //     throw DomainException(AlsaDomainErrorCode::ALS0005, snd_strerror(err));
    // }

    // fprintf(stdout, "hw_params access setted\n");

    // if ((err = snd_pcm_hw_params_set_format (capture_handle, hw_params, format)) < 0)
    // {
    //     // fprintf (stderr, "cannot set sample format (%s)\n",
    //     //      snd_strerror (err));
    //     //
    //     // return;

    //     throw DomainException(AlsaDomainErrorCode::ALS0006, snd_strerror(err));
    // }

    // fprintf(stdout, "hw_params format setted\n");

    // if ((err = snd_pcm_hw_params_set_rate_near (capture_handle, hw_params, &rate, 0)) < 0)
    // {
    //     // fprintf (stderr, "cannot set sample rate (%s)\n",
    //     //      snd_strerror (err));
    //     //
    //     // return;

    //     throw DomainException(AlsaDomainErrorCode::ALS0007, snd_strerror(err));
    // }

    // fprintf(stdout, "hw_params rate setted\n");

    // if ((err = snd_pcm_hw_params_set_channels (capture_handle, hw_params, 2)) < 0)
    // {
    //     // fprintf (stderr, "cannot set channel count (%s)\n",
    //     //      snd_strerror (err));
    //     //
    //     // return;

    //     throw DomainException(AlsaDomainErrorCode::ALS0008, snd_strerror(err));
    // }

    // fprintf(stdout, "hw_params channels setted\n");

    // if ((err = snd_pcm_hw_params (capture_handle, hw_params)) < 0)
    // {
    //     // fprintf (stderr, "cannot set parameters (%s)\n",
    //     //      snd_strerror (err));
    //     //
    //     // return;

    //     throw DomainException(AlsaDomainErrorCode::ALS0009, snd_strerror(err));
    // }

    // fprintf(stdout, "hw_params setted\n");

    // snd_pcm_hw_params_free (hw_params);

    // fprintf(stdout, "hw_params freed\n");

    // if ((err = snd_pcm_prepare (capture_handle)) < 0)
    // {
    //     // fprintf (stderr, "cannot prepare audio interface for use (%s)\n",
    //     //      snd_strerror (err));
    //     //
    //     // return;

    //     throw DomainException(AlsaDomainErrorCode::ALS0015, snd_strerror(err));
    // }

    // fprintf(stdout, "audio interface prepared\n");

    int sz = buffer_frames * snd_pcm_format_width(format) / 8 * channels;
    buffer = (char*) malloc(sz);

    fprintf(stdout, "buffer allocated\n");

    // for (i = 0; i < 10000; ++i)
    // for (int i = ((duration * 1000) / (rate / buffer_frames)); i > 0; i--)
    while(1)
    {
        if ((err = snd_pcm_readi (capture_handle, buffer, buffer_frames)) != buffer_frames)
        {
            throw DomainException(AlsaDomainErrorCode::ALS0016, snd_strerror(err));
        }
        // fprintf(stdout, "read %d done\n", i);

        for (size_t b = 0; b < sizeof(buffer); b++)
        {
            cout << (uint8_t) buffer[b];
        }
    }

    free(buffer);

    fprintf(stdout, "buffer freed\n");

    snd_pcm_close (capture_handle);
    fprintf(stdout, "audio interface closed\n");
#endif
}
