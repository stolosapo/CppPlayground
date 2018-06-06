#include "Mp3TagParser.h"

Mp3TagParser::Mp3TagParser(AudioType type, AudioTagVersion tagVersion) :
	type(type),
	tagVersion(tagVersion)
{

}

Mp3TagParser::~Mp3TagParser()
{

}

AudioType Mp3TagParser::getType()
{
	return type;
}

AudioTagVersion Mp3TagParser::getTagVersion()
{
	return tagVersion;
}