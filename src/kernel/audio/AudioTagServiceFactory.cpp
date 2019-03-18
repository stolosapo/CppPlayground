#include "AudioTagServiceFactory.h"
#include "TagLib/TagLibAudioTagService.h"
#include "SimpleAudioTag/SimpleAudioTagService.h"

AudioTagServiceFactory::AudioTagServiceFactory()
{

}

IService *AudioTagServiceFactory::create()
{
	IService* srv;

#ifdef TAGLIB
	srv = (IService*) new TagLibAudioTagService;
#else
	srv = (IService*) new SimpleAudioTagService;
#endif

	return srv;
}
