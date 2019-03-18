#include "AlsaCapture.h"

#include <stdio.h>
#include <stdlib.h>

#ifdef ALSA
#include <alsa/asoundlib.h>
#endif

#include "../../exception/domain/DomainException.h"
#include "exception/AlsaDomainErrorCode.h"

/*
        http://equalarea.com/paul/alsa-audio.html
        https://gist.github.com/albanpeignier/104902
        https://linuxconfig.org/how-to-test-microphone-with-audio-linux-sound-architecture-alsa
*/

AlsaCapture::AlsaCapture()
{

}

AlsaCapture::~AlsaCapture()
{

}

void AlsaCapture::capture()
{
#ifdef ALSA
        int i;
        int err;
        char *buffer;
        short buf[128];

        int buffer_frames = 128;
        unsigned int rate = 44100;

        const char* dev = "hw:0,0";

        snd_pcm_t *capture_handle;
        snd_pcm_hw_params_t *hw_params;
        snd_pcm_format_t format = SND_PCM_FORMAT_S16_LE;

        if ((err = snd_pcm_open (&capture_handle, dev, SND_PCM_STREAM_CAPTURE, 0)) < 0)
        {
                fprintf (stderr, "cannot open audio device %s (%s)\n",
                     dev,
                     snd_strerror (err));
                // return;

                throw DomainException(AlsaDomainErrorCode::ALS0002, snd_strerror(err));
        }

        fprintf(stdout, "audio interface opened\n");

        if ((err = snd_pcm_hw_params_malloc (&hw_params)) < 0)
        {
                // fprintf (stderr, "cannot allocate hardware parameter structure (%s)\n",
                //      snd_strerror (err));
                //
                // return;

                throw DomainException(AlsaDomainErrorCode::ALS0003, snd_strerror(err));
        }

        fprintf(stdout, "hw_params allocated\n");

        if ((err = snd_pcm_hw_params_any (capture_handle, hw_params)) < 0)
        {
                // fprintf (stderr, "cannot initialize hardware parameter structure (%s)\n",
                //      snd_strerror (err));
                //
                // return;

                throw DomainException(AlsaDomainErrorCode::ALS0004, snd_strerror(err));
        }

        fprintf(stdout, "hw_params initialized\n");

        if ((err = snd_pcm_hw_params_set_access (capture_handle, hw_params, SND_PCM_ACCESS_RW_INTERLEAVED)) < 0)
        {
                // fprintf (stderr, "cannot set access type (%s)\n",
                //      snd_strerror (err));
                //
                // return;

                throw DomainException(AlsaDomainErrorCode::ALS0005, snd_strerror(err));
        }

        fprintf(stdout, "hw_params access setted\n");

        if ((err = snd_pcm_hw_params_set_format (capture_handle, hw_params, format)) < 0)
        {
                // fprintf (stderr, "cannot set sample format (%s)\n",
                //      snd_strerror (err));
                //
                // return;

                throw DomainException(AlsaDomainErrorCode::ALS0006, snd_strerror(err));
        }

        fprintf(stdout, "hw_params format setted\n");

        if ((err = snd_pcm_hw_params_set_rate_near (capture_handle, hw_params, &rate, 0)) < 0)
        {
                // fprintf (stderr, "cannot set sample rate (%s)\n",
                //      snd_strerror (err));
                //
                // return;

                throw DomainException(AlsaDomainErrorCode::ALS0007, snd_strerror(err));
        }

        fprintf(stdout, "hw_params rate setted\n");

        if ((err = snd_pcm_hw_params_set_channels (capture_handle, hw_params, 2)) < 0)
        {
                // fprintf (stderr, "cannot set channel count (%s)\n",
                //      snd_strerror (err));
                //
                // return;

                throw DomainException(AlsaDomainErrorCode::ALS0008, snd_strerror(err));
        }

        fprintf(stdout, "hw_params channels setted\n");

        if ((err = snd_pcm_hw_params (capture_handle, hw_params)) < 0)
        {
                // fprintf (stderr, "cannot set parameters (%s)\n",
                //      snd_strerror (err));
                //
                // return;

                throw DomainException(AlsaDomainErrorCode::ALS0009, snd_strerror(err));
        }

        fprintf(stdout, "hw_params setted\n");

        snd_pcm_hw_params_free (hw_params);

        fprintf(stdout, "hw_params freed\n");

        if ((err = snd_pcm_prepare (capture_handle)) < 0)
        {
                // fprintf (stderr, "cannot prepare audio interface for use (%s)\n",
                //      snd_strerror (err));
                //
                // return;

                throw DomainException(AlsaDomainErrorCode::ALS0015, snd_strerror(err));
        }

        fprintf(stdout, "audio interface prepared\n");

        buffer = (char*) malloc(128 * snd_pcm_format_width(format) / 8 * 2);

        fprintf(stdout, "buffer allocated\n");

        for (i = 0; i < 10; ++i)
        {
                if ((err = snd_pcm_readi (capture_handle, buffer, buffer_frames)) != buffer_frames)
                {
                        // fprintf (stderr, "read from audio interface failed (%s)\n",
                        //        snd_strerror (err));
                        //
                        // return;

                        throw DomainException(AlsaDomainErrorCode::ALS0016, snd_strerror(err));
                }
                fprintf(stdout, "read %d done\n", i);
        }

        free(buffer);

        fprintf(stdout, "buffer freed\n");

        snd_pcm_close (capture_handle);
        fprintf(stdout, "audio interface closed\n");
#endif
}
