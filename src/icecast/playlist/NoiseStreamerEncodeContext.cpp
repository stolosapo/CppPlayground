#include "NoiseStreamerEncodeContext.h"

NoiseStreamerEncodeContext::NoiseStreamerEncodeContext(
    Thread* encodeThread,
    AudioEncodingService* encSrv,
    string pcmOutPath,
    string mp3OutPath,
    AudioEncodeMode encodeMode,
    AudioBitrate audioBitrate,
    int samplerate,
    int quality)
    : encodeThread(encodeThread),
    encSrv(encSrv),
    pcmOutPath(pcmOutPath),
    mp3OutPath(mp3OutPath),
    encodeMode(encodeMode),
    audioBitrate(audioBitrate),
    samplerate(samplerate),
    quality(quality)
{

}

NoiseStreamerEncodeContext::~NoiseStreamerEncodeContext()
{

}

Thread* NoiseStreamerEncodeContext::getEncodeThread()
{
    return encodeThread;
}

AudioEncodingService* NoiseStreamerEncodeContext::getEncSrv()
{
    return encSrv;
}

string NoiseStreamerEncodeContext::getPcmOutPath()
{
    return pcmOutPath;
}

string NoiseStreamerEncodeContext::getMp3OutPath()
{
    return mp3OutPath;
}

AudioEncodeMode NoiseStreamerEncodeContext::getEncodeMode()
{
    return encodeMode;
}

AudioBitrate NoiseStreamerEncodeContext::getAudioBitrate()
{
    return audioBitrate;
}

int NoiseStreamerEncodeContext::getSamplerate()
{
    return samplerate;
}

int NoiseStreamerEncodeContext::getQuality()
{
    return quality;
}
