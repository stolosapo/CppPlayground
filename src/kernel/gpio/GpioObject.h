#ifndef GPIO_OBJECT_H__
#define GPIO_OBJECT_H__

#include <string>
using namespace std;

/**
 * GPIO Class
 * Purpose: Each object instantiated from this class will control a GPIO pin
 * The GPIO pin number must be passed to the overloaded class constructor
 */
class GpioObject
{
private:
    string gpionum; // GPIO number associated with the instance of an object

protected:
	virtual int setdir_gpio();

public:
    GpioObject();  // create a GPIO object that controls GPIO4 (default
    GpioObject(string gnum); // create a GPIO object that controls GPIOx, where x is passed to this constructor
    virtual ~GpioObject();

    int export_gpio(); // exports GPIO
    int unexport_gpio(); // unexport GPIO

    int setdir_gpio(string dir); // Set GPIO Direction
    int setval_gpio(string val); // Set GPIO Value (putput pins)

    int getval_gpio(string& val); // Get GPIO Value (input/ output pins)
    string get_gpionum(); // return the GPIO number associated with the instance of an object

};

#endif // GPIO_OBJECT_H__