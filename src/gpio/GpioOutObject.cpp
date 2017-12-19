#include "GpioOutObject.h"

GpioOutObject::GpioOutObject() : GpioObject()
{

}

GpioOutObject::GpioOutObject(string gnum) : GpioObject(gnum)
{

}

GpioOutObject::~GpioOutObject()
{

}

int GpioOutObject::setdir_gpio()
{
	GpioObject::setdir_gpio("out");
}