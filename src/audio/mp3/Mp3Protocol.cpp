#include "Mp3Protocol.h"


const Mp3FrameData Mp3Protocol::FRAME = Mp3FrameData('A', 11, 31, "Frame sync");

const Mp3FrameData Mp3Protocol::MPEG = Mp3FrameData('B', 2, 20, "MPEG Audio version ID");

const Mp3FrameData Mp3Protocol::LAYER = Mp3FrameData('C', 2, 18, "Layer Description");

const Mp3FrameData Mp3Protocol::PROTECTION = Mp3FrameData('D', 1, 16, "Protection Bit");

const Mp3FrameData Mp3Protocol::BITRATE = Mp3FrameData('E', 4, 15, "Bitrate Index");

const Mp3FrameData Mp3Protocol::SAMPLERATE = Mp3FrameData('F', 2, 11, "Sampling rate frequency index");

const Mp3FrameData Mp3Protocol::PADDING = Mp3FrameData('G', 1, 9, "Padding bit");

const Mp3FrameData Mp3Protocol::PRIVATE = Mp3FrameData('H', 1, 8, "Private bit");

const Mp3FrameData Mp3Protocol::CHANNEL = Mp3FrameData('I', 2, 7, "Channel Mode");

const Mp3FrameData Mp3Protocol::EXTENSION = Mp3FrameData('J', 2, 5, "Mode extension");

const Mp3FrameData Mp3Protocol::COPYRIGHT = Mp3FrameData('K', 1, 3, "Copyright");

const Mp3FrameData Mp3Protocol::ORIGINAL = Mp3FrameData('L', 1, 2, "Original");

const Mp3FrameData Mp3Protocol::EMPHASIS = Mp3FrameData('M', 2, 1, "Emphasis");



Mp3Protocol::Mp3Protocol()
{

}

Mp3Protocol::~Mp3Protocol()
{

}