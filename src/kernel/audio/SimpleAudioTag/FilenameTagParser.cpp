#include "FilenameTagParser.h"

#include "../../utils/FileHelper.h"

FilenameTagParser::FilenameTagParser() : AudioTagParser()
{

}

FilenameTagParser::~FilenameTagParser()
{

}

AudioTag* FilenameTagParser::parse(const char* filepath, FILE *file)
{
	string title = FileHelper::filename(filepath);

	return AudioTag::emptyWithTitle(title);
}
