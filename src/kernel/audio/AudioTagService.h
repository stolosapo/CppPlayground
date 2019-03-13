#ifndef AudioTagService_h__
#define AudioTagService_h__

#include <iostream>
#include <string>

#include "../service/IService.h"

#include "AudioTag.h"

using namespace std;

class AudioTagService: public IService
{
public:
	AudioTagService() {};
	virtual ~AudioTagService() {};

	virtual AudioTag* read(const char* filename) = 0;
};

#endif // AudioTagService_h__
