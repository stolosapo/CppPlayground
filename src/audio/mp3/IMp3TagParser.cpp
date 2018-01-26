#include "IMp3TagParser.h"

IMp3TagParser::IMp3TagParser(AudioType type, AudioTagVersion tagVersion) :
	type(type),
	tagVersion(tagVersion)
{

}

IMp3TagParser::~IMp3TagParser()
{

}

AudioType IMp3TagParser::getType()
{
	return type;
}

AudioTagVersion IMp3TagParser::getTagVersion()
{
	return tagVersion;
}