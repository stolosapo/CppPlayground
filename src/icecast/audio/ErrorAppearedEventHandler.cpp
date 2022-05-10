#include "ErrorAppearedEventHandler.h"

#include "../../kernel/exception/domain/DomainException.h"
#include "../../kernel/exception/ExceptionMapper.h"

ErrorAppearedEventHandler::ErrorAppearedEventHandler(
    NoiseStreamer *noiseStreamer)
    : EventHandler(),
    noiseStreamer(noiseStreamer)
{

}

ErrorAppearedEventHandler::~ErrorAppearedEventHandler()
{

}

void ErrorAppearedEventHandler::onEvent(void* sender, EventArgs* e)
{
    noiseStreamer->incrementErrorCounter();

    if (e != NULL)
    {
        delete e;
    }
}
