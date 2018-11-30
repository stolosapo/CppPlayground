#ifndef AudioTagParser_h__
#define AudioTagParser_h__

#include <fstream>

#include "../AudioTag.h"

using namespace std;

class AudioTagParser
{
public:
	AudioTagParser() {};
	virtual ~AudioTagParser() {};

	virtual AudioTag* parse(const char* filepath, FILE* file) = 0;
};

#endif // AudioTagParser_h__
