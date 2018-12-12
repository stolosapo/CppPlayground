#include "AudioBitrateConverter.h"

AudioBitrateConverter::AudioBitrateConverter()
{

}

AudioBitrateConverter::~AudioBitrateConverter()
{

}

AudioBitrate AudioBitrateConverter::convert(int number)
{
    switch (number)
    {
        case 0:
            return NO_BR;

        case 8:
            return BR_8kbps;

    	case 16:
            return BR_16kbps;

    	case 24:
            return BR_24kbps;

    	case 32:
            return BR_32kbps;

    	case 40:
            return BR_40kbps;

    	case 48:
            return BR_48kbps;

    	case 56:
            return BR_56kbps;

    	case 64:
            return BR_64kbps;

    	case 80:
            return BR_80kbps;

    	case 96:
            return BR_96kbps;

    	case 112:
            return BR_112kbps;

    	case 128:
            return BR_128kbps;

    	case 144:
            return BR_144kbps;

    	case 160:
            return BR_160kbps;

    	case 192:
            return BR_192kbps;

    	case 224:
            return BR_224kbps;

    	case 256:
            return BR_256kbps;

    	case 320:
            return BR_320kbps;

        default:
            return NO_BR;
    }
}

int AudioBitrateConverter::convert(AudioBitrate bitrate)
{
    return (int) bitrate;
}
