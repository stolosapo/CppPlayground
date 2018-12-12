#ifndef AudioBitrateConverter_h__
#define AudioBitrateConverter_h__

#include "AudioBitrate.h"

class AudioBitrateConverter
{
public:
	AudioBitrateConverter();
	virtual ~AudioBitrateConverter();

	static AudioBitrate convert(int number);
    static int convert(AudioBitrate bitrate);

};

#endif // AudioBitrateConverter_h__
