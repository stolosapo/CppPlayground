#ifndef AudioStream_h__
#define AudioStream_h__

#include <string>

#include "AudioStreamType.h"

using namespace std;

class AudioStream
{
private:
        AudioStreamType type;

        string path;

        size_t filesize;
        size_t bytesRead;
        unsigned int bitrate;
        unsigned int samplerate;
        unsigned int channels;

        void* data;

public:
	AudioStream();
	virtual ~AudioStream();

        size_t read();
        size_t close();

};

#endif // AudioStream_h__
