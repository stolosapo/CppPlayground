#ifndef NoiseStreamerStateHandler_h__
#define NoiseStreamerStateHandler_h__

#include <iostream>

#include "../../kernel/task/Locker.h"

using namespace std;

class NoiseStreamerStateHandler
{
private:
    Locker _locker;

    void changeState(void* newState);

protected:
    void getState();

public:
	NoiseStreamerStateHandler();
	virtual ~NoiseStreamerStateHandler();

    void load();
    void stream();
    void shutdown();

};

#endif // NoiseStreamerStateHandler_h__
