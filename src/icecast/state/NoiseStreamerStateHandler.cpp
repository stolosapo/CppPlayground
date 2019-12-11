#include "NoiseStreamerStateHandler.h"

NoiseStreamerStateHandler::NoiseStreamerStateHandler()
{
    _locker.init();
}

NoiseStreamerStateHandler::~NoiseStreamerStateHandler()
{
    _locker.destroy();
}

void NoiseStreamerStateHandler::changeState(void* newState)
{
    _locker.lock();

    // if (state != NULL)
    // {
    //     delete state;
    // }
    //
    // state = newState;

    _locker.unlock();
}

void NoiseStreamerStateHandler::getState()
{

}

void NoiseStreamerStateHandler::load()
{

}

void NoiseStreamerStateHandler::stream()
{

}

void NoiseStreamerStateHandler::shutdown()
{

}
