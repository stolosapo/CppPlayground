#ifndef GpioOutObject_h__
#define GpioOutObject_h__

#include <string>

#include "GpioObject.h"

using namespace std;

class GpioOutObject : public GpioObject
{
public:
    GpioOutObject();
    GpioOutObject(string gnum);
    virtual ~GpioOutObject();

    int setdir_gpio();

};

#endif // GpioOutObject_h__