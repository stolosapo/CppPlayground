#ifndef FilenameAudioTagService_h__
#define FilenameAudioTagService_h__

#include <iostream>
#include <string>

#include "../AudioTagService.h"

using namespace std;

class FilenameAudioTagService: public AudioTagService
{
public:
	FilenameAudioTagService();
	virtual ~FilenameAudioTagService();

	virtual AudioTag* read(const char* filename);
};

#endif // FilenameAudioTagService_h__
