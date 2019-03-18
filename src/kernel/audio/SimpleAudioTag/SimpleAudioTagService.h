#ifndef SimpleAudioTagService_h__
#define SimpleAudioTagService_h__

#include <iostream>
#include <string>
#include <vector>

#include "../AudioTagService.h"

using namespace std;

class SimpleAudioTagService: public AudioTagService
{
public:
	SimpleAudioTagService();
	virtual ~SimpleAudioTagService();

	virtual AudioTag* read(const char* filename);
};

#endif // SimpleAudioTagService_h__
