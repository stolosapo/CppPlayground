#include "NoiseStreamerHealth.h"

#include "../exception/NoiseStreamerDomainErrorCode.h"
#include "../../kernel/exception/domain/DomainException.h"
#include "../../kernel/converter/Convert.h"


const int NoiseStreamerHealth::ERROR_THRESHOLD = 10;
const int NoiseStreamerHealth::SHOUT_QUEUE_LENGTH_THRESHOLD = 6000000;

NoiseStreamerHealth::NoiseStreamerHealth()
{
    resetErrorCounter();
}

NoiseStreamerHealth::~NoiseStreamerHealth()
{

}

void NoiseStreamerHealth::resetErrorCounter()
{
    this->errorCounter = 0;
}

void NoiseStreamerHealth::incrementErrorCounter()
{
    errorCounter++;
}

void NoiseStreamerHealth::checkIfErrorCounterThresholdReached()
{
    if (errorCounter >= ERROR_THRESHOLD)
    {
        throw DomainException(NoiseStreamerDomainErrorCode::NSS0023);
    }
}

void NoiseStreamerHealth::checkIfShoutQueueLengthThresholdReached()
{
    if (shoutQueueLength >= SHOUT_QUEUE_LENGTH_THRESHOLD)
    {
        throw DomainException(NoiseStreamerDomainErrorCode::NSS0029, Convert<int>::NumberToString(shoutQueueLength));
    }
}

void NoiseStreamerHealth::setShoutQueueLenth(int queueLength)
{
    shoutQueueLength = queueLength;
}

int NoiseStreamerHealth::getShoutQueueLength()
{
    return shoutQueueLength;
}
