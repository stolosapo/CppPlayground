#include "NoiseStreamerEncodeContext.h"

NoiseStreamerEncodeContext::NoiseStreamerEncodeContext(Thread* encodeThread, AudioEncodingService* encSrv, string pcmOutPath, string mp3OutPath)
    : encodeThread(encodeThread), encSrv(encSrv), pcmOutPath(pcmOutPath), mp3OutPath(mp3OutPath)
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
