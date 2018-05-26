#include "FilenameTagParser.h"

#include "../../utils/FileHelper.h"

FilenameTagParser::FilenameTagParser() : AudioTagParser()
{

}

FilenameTagParser::~FilenameTagParser()
{

}

bool FilenameTagParser::isCorrectVersion(const char* filepath, FILE* file)
{
	return true;
}

AudioTag* FilenameTagParser::parse(const char* filepath, FILE *file)
{
	string title = FileHelper::filename(filepath);

	return new AudioTag(title,
			"",
			"",
			"",
			"",
			0,
			0,
			0,
			"--:--",
			0,
			0,
			0);
}