#ifndef TagLibAudioTagService_h__
#define TagLibAudioTagService_h__

#include <iostream>
#include <string>

#include "../AudioTagService.h"

using namespace std;

class TagLibAudioTagService: public AudioTagService
{
public:
	TagLibAudioTagService();
	virtual ~TagLibAudioTagService();

	virtual AudioTag* read(const char* filename);
};

#endif // TagLibAudioTagService_h__
