#ifndef SimpleAudioEncodingService_h__
#define SimpleAudioEncodingService_h__

#include <iostream>
#include <string>

#include "../AudioEncodingService.h"

using namespace std;

class SimpleAudioEncodingService: public AudioEncodingService
{
public:
	SimpleAudioEncodingService();
	virtual ~SimpleAudioEncodingService();

	virtual void encode(const char* filename);
};

#endif // SimpleAudioEncodingService_h__
