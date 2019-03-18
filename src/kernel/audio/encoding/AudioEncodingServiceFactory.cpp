#include "AudioEncodingServiceFactory.h"

#include "lame/LameAudioEncodingService.h"
#include "simple/SimpleAudioEncodingService.h"

AudioEncodingServiceFactory::AudioEncodingServiceFactory()
{

}

AudioEncodingServiceFactory::~AudioEncodingServiceFactory()
{

}

IService *AudioEncodingServiceFactory::create()
{
	IService* srv;

#ifdef LAME
	srv = (IService*) new LameAudioEncodingService;
#else
	srv = (IService*) new SimpleAudioEncodingService;
#endif

	return srv;
}
