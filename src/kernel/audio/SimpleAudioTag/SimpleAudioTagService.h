#ifndef SimpleAudioTagService_h__
#define SimpleAudioTagService_h__

#include <iostream>
#include <string>
#include <vector>

#include "../AudioTagService.h"
#include "AudioTagParser.h"

using namespace std;

class SimpleAudioTagService: public AudioTagService
{
private:
	vector<AudioTagParser*> tagParsers;

	void registerParsers();

public:
	SimpleAudioTagService();
	virtual ~SimpleAudioTagService();

	virtual AudioTag* read(const char* filename);
};

#endif // SimpleAudioTagService_h__
