#include "GpioInObject.h"

GpioInObject::GpioInObject() : GpioObject()
{

}

GpioInObject::GpioInObject(string gnum) : GpioObject(gnum)
{

}

GpioInObject::~GpioInObject()
{

}

int GpioInObject::setdir_gpio()
{
	GpioObject::setdir_gpio("in");
}