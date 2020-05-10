#ifndef AlsaCapture_h__
#define AlsaCapture_h__

#include <iostream>
#include <string>

#ifdef ALSA
#include <alsa/asoundlib.h>
#endif

using namespace std;

class AlsaCapture
{
private:

#ifdef ALSA
	snd_pcm_t *snd_handle;
#endif

public:
	AlsaCapture();
	virtual ~AlsaCapture();

	void initialize();

	void playback();
    void capture();
};

#endif // AlsaCapture_h__
