#ifndef Mp3Protocol_h__
#define Mp3Protocol_h__

#include <string>

#include "Mp3FrameData.h"

using namespace std;

class Mp3Protocol
{
public:
	static const Mp3FrameData FRAME;

	static const Mp3FrameData MPEG;

	static const Mp3FrameData LAYER;
	
	static const Mp3FrameData PROTECTION;

	static const Mp3FrameData BITRATE;

	static const Mp3FrameData SAMPLERATE;

	static const Mp3FrameData PADDING;

	static const Mp3FrameData PRIVATE;

	static const Mp3FrameData CHANNEL;

	static const Mp3FrameData EXTENSION;
	
	static const Mp3FrameData COPYRIGHT;

	static const Mp3FrameData ORIGINAL;

	static const Mp3FrameData EMPHASIS;


	Mp3Protocol();
	virtual ~Mp3Protocol();

};

#endif // Mp3Protocol_h__