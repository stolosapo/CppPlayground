#ifndef AudioEncodingService_h__
#define AudioEncodingService_h__

#include <iostream>
#include <string>

#include "../../service/IService.h"

using namespace std;

class AudioEncodingService: public IService
{
public:
	AudioEncodingService() {};
	virtual ~AudioEncodingService() {};

	virtual void encode(const char* filename) = 0;
};

#endif // AudioEncodingService_h__
