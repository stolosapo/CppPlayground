#include "NoiseStreamerHealth.h"

NoiseStreamerHealth::NoiseStreamerHealth()
{

}

NoiseStreamerHealth::~NoiseStreamerHealth()
{

}

void NoiseStreamerHealth::setShoutQueueLenth(int queueLength)
{
    shoutQueueLength = queueLength;
}

int NoiseStreamerHealth::getShoutQueueLength()
{
    return shoutQueueLength;
}
