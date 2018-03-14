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

	virtual AudioTag* parse(FILE* file) = 0;
	virtual bool isCorrectVersion(FILE* file) = 0;
};

#endif // AudioTagParser_h__
