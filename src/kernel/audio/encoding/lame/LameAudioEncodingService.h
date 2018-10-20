#ifndef LameAudioEncodingService_h__
#define LameAudioEncodingService_h__

#include <iostream>
#include <string>

#include "../AudioEncodingService.h"

using namespace std;

class LameAudioEncodingService: public AudioEncodingService
{
public:
	LameAudioEncodingService();
	virtual ~LameAudioEncodingService();

	virtual void encode(const char* filename);
};

#endif // LameAudioEncodingService_h__
