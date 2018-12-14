#ifndef AudioEncodingService_h__
#define AudioEncodingService_h__

#include <iostream>
#include <string>

#include "../../service/IService.h"
#include "../AudioTag.h"

using namespace std;

class AudioEncodingService: public IService
{
public:
	AudioEncodingService() {};
	virtual ~AudioEncodingService() {};

    virtual string version() = 0;

    virtual void encode(string pcm_in_file, string mp3_out_file, AudioTag* settings) = 0;
    virtual void decode(string mp3_in_file, string pcm_out_file) = 0;
};

#endif // AudioEncodingService_h__
