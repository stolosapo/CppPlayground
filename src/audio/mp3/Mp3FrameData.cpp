#include "Mp3FrameData.h"

Mp3FrameData::Mp3FrameData(
		const char sign, 
		const unsigned int length, 
		const unsigned int position, 
		const string description)
{
	this->sign = sign;
	this->length = length;
	this->position = position;
	this->description = description;
}

Mp3FrameData::~Mp3FrameData()
{

}

const char Mp3FrameData::getSign() const
{
	return sign;
}

const unsigned int Mp3FrameData::getLength() const
{
	return length;
}

const unsigned int Mp3FrameData::getPosition() const
{
	return position;
}

const string Mp3FrameData::getDescription() const
{
	return description;
}
