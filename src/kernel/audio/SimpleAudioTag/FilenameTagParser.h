#ifndef FilenameTagParser_h__
#define FilenameTagParser_h__

#include <iostream>
#include <string>
#include <fstream>

#include "AudioTagParser.h"
#include "../AudioTag.h"

using namespace std;

class FilenameTagParser : public AudioTagParser
{
public:
	FilenameTagParser();
	virtual ~FilenameTagParser();

	virtual AudioTag* parse(const char* filepath, FILE* file);
};

#endif // FilenameTagParser_h__
