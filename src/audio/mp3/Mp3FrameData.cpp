#include "Mp3FrameData.h"

Mp3FrameData::Mp3FrameData(
		const char sign, 
		const unsigned int length, 
		const unsigned int position, 
		const string description)
{
	this->_sign = sign;
	this->_length = length;
	this->_position = position;
	this->_description = description;
}

Mp3FrameData::~Mp3FrameData()
{

}

const char Mp3FrameData::sign() const
{
	return _sign;
}

const unsigned int Mp3FrameData::length() const
{
	return _length;
}

const unsigned int Mp3FrameData::position() const
{
	return _position;
}

const string Mp3FrameData::description() const
{
	return _description;
}
