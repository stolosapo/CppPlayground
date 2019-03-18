#ifndef GpioInObject_h__
#define GpioInObject_h__

#include <string>

#include "GpioObject.h"

using namespace std;

class GpioInObject : public GpioObject
{
public:
    GpioInObject();
    GpioInObject(string gnum);
    virtual ~GpioInObject();

    int setdir_gpio();

};

#endif // GpioInObject_h__